#include <iostream>
using namespace std;


class Robot{
    public:
    Robot(int values){
        cout << "initialize with sensor values " <<values<< endl;
        sensorread();
    }
        void sensorcalibrate(){
            cout << "calibrate the sensor d1 now..." << endl;
        }

        void sensorread(){
            cout << "read the sensor d1 now..." << endl;
        }

        void sensorprocess(){
            cout << "process the sensor d1 now..." << endl;
        }
    private:
        int values;
        };
       
int main(){
    Robot robot_1(50);
    robot_1.sensorcalibrate();

    return 0;
}