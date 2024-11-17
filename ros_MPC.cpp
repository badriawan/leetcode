#include <rclcpp/rclcpp.hpp>
#include <geometry_msgs/msg/twist.hpp>
#include <nav_msgs/msg/odometry.hpp>
#include <casadi/casadi.hpp>

using namespace casadi;
using namespace std;

class MPCControllerNode : public rclcpp::Node {
public:
    MPCControllerNode() : Node("mpc_controller_node") {
        // Target position
        x_target_ = 5.0;
        y_target_ = 5.0;
        theta_target_ = 0.0;

        // Set up publisher to send velocity commands
        cmd_vel_pub_ = this->create_publisher<geometry_msgs::msg::Twist>("cmd_vel", 10);

        // Set up subscriber to receive odometry data
        odom_sub_ = this->create_subscription<nav_msgs::msg::Odometry>(
            "odom", 10, std::bind(&MPCControllerNode::odomCallback, this, std::placeholders::_1)
        );

        // Timer to run MPC at regular intervals
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(100), std::bind(&MPCControllerNode::mpcLoop, this)
        );

        // Set time step
        dt_ = 0.1;
        N_ = 10;

        // Initialize MPC model
        initializeMPC();
    }

private:
    void initializeMPC() {
        // Variables and parameters for MPC
        x_ = SX::sym("x");
        y_ = SX::sym("y");
        theta_ = SX::sym("theta");
        v_ = SX::sym("v");
        omega_ = SX::sym("omega");

        // Kinematic model
        SX rhs = SX::vertcat({
            x_ + v_ * cos(theta_) * dt_,
            y_ + v_ * sin(theta_) * dt_,
            theta_ + omega_ * dt_
        });
        f_ = Function("f", {x_, y_, theta_, v_, omega_}, {rhs});

        // Cost function weights
        Q_ = SX::diag(SX({10, 10, 1}));
        R_ = SX::diag(SX({0.1, 0.1}));
    }

    void odomCallback(const nav_msgs::msg::Odometry::SharedPtr msg) {
        // Update robot's current state from odometry data
        x_current_ = msg->pose.pose.position.x;
        y_current_ = msg->pose.pose.position.y;
        theta_current_ = tf2::getYaw(msg->pose.pose.orientation);
    }

    void mpcLoop() {
        // Run MPC to compute optimal velocity commands
        auto result = computeMPC(x_current_, y_current_, theta_current_);

        // Publish computed velocities
        auto twist_msg = geometry_msgs::msg::Twist();
        twist_msg.linear.x = static_cast<double>(result["v"]);
        twist_msg.angular.z = static_cast<double>(result["omega"]);
        cmd_vel_pub_->publish(twist_msg);
    }

    std::map<std::string, double> computeMPC(double x_init, double y_init, double theta_init) {
        // Horizon prediction matrices
        SX X = SX::sym("X", 3, N_+1);
        SX U = SX::sym("U", 2, N_);

        SX cost = 0;
        std::vector<SX> constraints;
        constraints.push_back(X(Slice(), 0) - SX::vertcat({x_init, y_init, theta_init}));

        for (int k = 0; k < N_; ++k) {
            SX state_error = X(Slice(), k) - SX::vertcat({x_target_, y_target_, theta_target_});
            SX control_input = U(Slice(), k);
            cost += SX::dot(state_error, Q_ * state_error) + SX::dot(control_input, R_ * control_input);

            SX x_next = f_(SXVector{X(0, k), X(1, k), X(2, k), U(0, k), U(1, k)})[0];
            constraints.push_back(X(Slice(), k+1) - x_next);
        }

        SXDict nlp = {{"x", vertcat(X, U)}, {"f", cost}, {"g", vertcat(constraints)}};
        Function solver = nlpsol("solver", "ipopt", nlp);

        DM X_init = DM::zeros(3, N_+1);
        DM U_init = DM::zeros(2, N_);

        std::map<std::string, DM> arg;
        arg["x0"] = vertcat(X_init, U_init);
        arg["lbx"] = -DM::inf(3, N_+1);
        arg["ubx"] = DM::inf(3, N_+1);
        arg["lbg"] = DM::zeros(3 * (N_ + 1));
        arg["ubg"] = DM::zeros(3 * (N_ + 1));

        auto result = solver(arg);

        std::map<std::string, double> opt_u;
        opt_u["v"] = static_cast<double>(result["x"](3 * (N_ + 1)));
        opt_u["omega"] = static_cast<double>(result["x"](3 * (N_ + 1) + 1));

        return opt_u;
    }

    rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr cmd_vel_pub_;
    rclcpp::Subscription<nav_msgs::msg::Odometry>::SharedPtr odom_sub_;
    rclcpp::TimerBase::SharedPtr timer_;

    double x_target_, y_target_, theta_target_;
    double x_current_, y_current_, theta_current_;
    double dt_;
    int N_;

    SX x_, y_, theta_, v_, omega_;
    Function f_;
    SX Q_, R_;
};

int main(int argc, char **argv) {
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MPCControllerNode>());
    rclcpp::shutdown();
    return 0;
}
