#include "robot2.h"


using namespace std;
//using namespace Robot::A;



int main() {
    //int velocity[2] = {10,10};
    //vector<int>* velocity = new vector<int>{10,10};
    vector<int> input = {10,10};
    vector<int>* velocity = &input;
    char way = 'B';
    char way2 = 'M';
    Robot::A::robot<int> a(velocity,way);
    return 0;
}