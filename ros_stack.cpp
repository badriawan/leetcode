// #include "rosbot_class.hpp"
#include <vector>
#include <cmath>
#include <algorithm>
#include <stack>
#include "rclcpp/rclcpp.hpp"
#include "nav2_msgs/msg/odom.hpp"
#include "geometry_msgs/msg/point.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;






class Navigation : public rclcpp::Node
{
    public:
    Navigation(): Node("nav"){
    
   
    _publisher = this->create_publisher<geometry_msgs::msg::Point>("/goal",10);
    //_subscriber = this->create_subscription<nav_msgs::msg::Odom>("/odom",1000,std::bind(&Navigation::processCallback,this,_1));
    
    _timer = this->create_wall_timer(std::chrono::milliseconds(10),std::bind(&Navigation::processCallback,this));

    getTarget(2,2);
    getTarget(3,3);
    
    }


        
    void processCallback(){
        if(!Goals.empty()){

            auto dest = Goals.top();

            step_size = 0.5;

            error_pos = sqrt(pow(dest.x - cur_position.x,2) + pow(dest.y - cur_position.y,2));
            angle_to_goal = atan2(dest.y - cur_position.y,dest.x - cur_position.x);

            cur_position.x += step_size * cos(angle_to_goal);
            cur_position.y += step_size * sin(angle_to_goal);

            if(error_pos <= 1){
            Goals.pop();
            if(!Goals.empty()){
            auto next = Goals.top();
            RCLCPP_INFO(this->get_logger(),"The next goal is '%.2f' '%.2f' ",next.x,next.y);
            }
            }
            
            _publisher->publish(cur_position);

        }
        else{

            RCLCPP_INFO(this->get_logger(),"The robot has achieved all of its goals.");

        }

     
      }


    private:

    void getTarget(int x,int y){
    geometry_msgs::msg::Point goal;
    goal.x = x;
    goal.y = y;
    goal.z = 0;

    Goals.push(goal);

    }    


    rclcpp::Publisher<geometry_msgs::msg::Point>::SharedPtr _publisher;
    rclcpp::TimerBase::SharedPtr _timer;
    stack<geometry_msgs::msg::Point> Goals;
    geometry_msgs::msg::Point cur_position={0,0,0};
    double error_pos;
    double angle_to_goal;




};


int main(int argc, char * argv[]) {
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<Navigation>());
    rclcpp::shutdown();
    return 0;
}