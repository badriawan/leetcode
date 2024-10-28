// #include "rosbot_class.hpp"
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Rosbot //: public Circle
{
    public:
    // Rosbot(int r) : Circle(r)
    // { Luas(r);}
    Rosbot(int i){
        //Circle c(i);
        //double x = c(i);
        //cout << "The area of the circle is" << c.(i) << endl;

    }

//   void Luas(int r) {
//     //Area(r);
//     cout << "The area of the circle is" << Area(r) << endl;
//}




};

int main(int argc, char **argv) {
  //ros::init(argc, argv, "Rosbot_move_node");
  Rosbot rosbot_moves(5);
  //rosbot_moves.Luas();
  return 0;
}