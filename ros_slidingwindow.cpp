// #include "rosbot_class.hpp"
#include <vector>
#include <cmath>
#include <algorithm>
#include "rclcpp/rclcpp.hpp"
#include "nav_msgs/odom.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

class Sliding : public rclcpp::Node
{
    public:
    Sliding(): Node("sliding_window"){}
    //_publisher = this->create_publisher<std_msgs::msg::String>("/data",10);
    _subscriber = this->create_subscription<nav_msgs::msg::Odom>("/odom",1000,std::bind(&Sliding::processCallback,this,_1));



        
    void processCallback(const& nav_msgs::msg::Odom::SharedPtr odom){
      //get the input
      data = odom->twist.twist.linear.x;
      is_array.pushback(data);
      //processing input with logic 
      //remove the previous left sub element by substraction and add the new next sub element by sum.
      int a = is_array.size();
      
      if(a>window_size){
        is_array.erase(is_array.begin());

      }
      

      sub_array = std::accumulate(is_array.begin(),is_array.end(),0.0);
      max_sum = max(max_sum,sub_array); //compare the max previous with the new value
      cout << "sub array " << sub_array << endl;

      }

      //int max_sum = *std::max_element(new_array.begin(),new_array.end());

    //RCLCPP_INFO(this->get_logger(), "I heard: '%s'", msg->data.c_str());

        RCLCPP_INFO(this->get_logger(),"The maximum history distance for 3 seconds is '%d' ",max_sum);

    }    


    private:    
    rclcpp::Subscription<nav_msgs::msg::Odom>::SharedPtr _subscriber;
    vector<double> is_array = {};
    double data;
    int sub_array;
    int window_size = 3;
    vector<int> new_array = {};
    double max_sum = 0.0;




};


int main(int argc, char * argv[]) {
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<Sliding>());
    rclcpp::shutdown();
    return 0;
}