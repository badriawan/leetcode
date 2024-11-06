#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <unordered_map>
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "sensor_msgs/msg/laser_scan.hpp"
#include "sensor_msgs/msg/camera.hpp"
#include "sensor_msgs/msg/temperature.hpp"




using namespace std::chrono_literals;
using std::placeholders::_1;






class Robot : public rclcpp::Node{
    public:
    Robot():Node("hashmap_ros2"){

    _sub = this->create_subscription<sensor_msgs::msg::Imu>("/imu",10,std::bind(&Robot::IMUCallback,this,_1));
    _sub2 = this->create_subscription<sensor_msgs::msg::LaserScan>("/laser_scan",10,std::bind(&Robot::LaserCallback,this,_1));
    _sub3 = this->create_subscription<sensor_msgs::msg::Camera>("/camera",10,std::bind(&Robot::CamCallback,this,_1));
    _sub4 = this->create_subscription<sensor_msgs::msg::Temperature>("/temperature",10,std::bind(&Robot::TempCallback,this,_1));


    _pub = this->create_publisher<std_msgs::msg::String>("/info",10);

    _timer = this->create_wall_timer(std::chrono::seconds(5),std::bind(&Robot::timerCallback,this));




}
    private:
    unordered_map<string,double> sensor;

    void IMUCallback(const sensor_msgs::msg::Imu::SharedPtr &imu_data){
        sensor["Imu"] = imu_data->data;    
    }

    void LaserCallback(const sensor_msgs::msg::LaserScan::SharedPtr &lidar_data){
        sensor["Lidar"] = lidar_data->data;    
    }

    void CamCallback(const sensor_msgs::msg::Camera::SharedPtr &cam_data){
        sensor["Camera"] = cam_data->data;
    }
    
    void TempCallback(const sensor_msgs::msg::Temperature::SharedPtr &temp_data){
        sensor["Temperature"] = temp_data->data;
    }

    void timerCallback(){
     for(auto& i : sensor){
        RCLCPP_INFO(this->get_logger(),"The value of '%s' is '%f' ",i.first.c_str(),i.second);
        }

        std_msgs::msg::String data;
        data.data  = "The Sensor data are " + to_string(sensor["Imu"]) + to_string(sensor["Lidar"]) + 
        to_string(sensor["Camera"]) + to_string(sensor["Temperature"]); 

        _pub->publish(data);

    }


    
    
    
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr _sub;
    rclcpp::Subscription<sensor_msgs::msg::LaserScan>::SharedPtr _sub2;
    rclcpp::Subscription<sensor_msgs::msg::Camera>::SharedPtr _sub3;
    rclcpp::Subscription<sensor_msgs::msg::Temperature>::SharedPtr _sub4;

    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr _pub;
    rclcpp::TimerBase::SharedPtr _timer;




};

int main(int argc,char * argv[]){
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<Robot>());
    rclcpp::shutdown();
    return 0;
}