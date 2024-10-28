#include "rosbot_control/rosbot_class.h"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Rosbot //define the class and variables
{
    public:
    Rosbot(){};
    RosbotClass R;
    manuever();
    

    private:
    //define the logic
    void manuever(){
        

        list<float> coordinates = R.get_position_full();

        while(!coordinates.empty()){
        cout << "Robot Position" << coordinates << endl;

        if(R.get_laser(180) < d && R.get_laser(90) < d){
            R.turn("clockwise",5);
        }
        if(R.get_laser(180) < d && R.get_laser(270) < d){
            R.turn("counterclockwise",5);
        }
        else{
            R.move_forward(10);

        }

        if(10<=R.get_position[1]<=15){
            R.turn("counterclockwise",5);
            R.move_forward(5)
            }
        
        }
    }

    int d = 5;
  

};

int main(int argc, char **argv) {
  //ros::init(argc, argv, "Rosbot_move_node");
  Rosbot rosbot_moves();
  //rosbot_moves.Luas();
  return 0;
}