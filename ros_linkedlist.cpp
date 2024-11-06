#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;
using std::placeholders::_1;

struct Node{
    int ID;
    std::string type;
    double data;
    Node* next;

};

void addJoint(Node*& head,int ID,std::string type,double data){
    Node* newjoint = new Node{id,type,data,nullptr};

    if(head == nullptr){
        head = newjoint;
    }
    else{
        Node* temp = head; //pointer disini tidak pakai new karena merujuk pada nilai pointernya bukan variable reference
        while(temp->next != nullptr){
            temp = temp->next; 
        }
        temp->next = newjoint; 

    }

}

std::string getSensorData(Node*& head){
    std::string result;
    Node* temp = head;
    while(temp != nullptr){
        result += "ID" + std::to_string(temp->ID) + "type" +
        temp->type + "data" + std::to_string(temp->data);
        temp = temp->next;
    }
    return result;
}



class Robot : public rclcpp::Node{
    public:
    Robot():Node("link_pub"){

    _pub = this->create_publisher<std_msgs::msg::String>"/sensor_data",10);

    _timer = this->create_wall_timer(std::chrono::seconds(2),std::bind(&Robot::timerCallback,this));

    addJoint(head,1,"IMU",3.12); //head is usefull to call or connect to the first node of linkedlist
    addJoint(head,2,"GPS",6.12); //when head has been fullfilled before, it means that the next head for new node is not nullptr


}
    private:
    void timerCallback(){
        std_msgs::msg::String data;
        data.data  = getSensorData(head); //ubah dulu type struct linkedlist ke string

        _pub->publish(data);



    }
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr _pub;
    rclcpp::TimerBase::SharedPtr _timer;
    Node* head = nullptr;


};

int main(int argc,char * argv[]){
    rclcpp::init(argc,argv);
    rclcpp::spin(std::make_shared<Robot>());
    rclcpp::shutdown();
    return 0;
}