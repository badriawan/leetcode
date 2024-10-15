#include <iostream>
#include <random>

//define all of the libraries and variables need
using namespace std;
//analyze the input needed = no input

class Position{
    public:
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> value(0, 11);
    
    // the output is random position of x and y 
    void output(){
        //lets define the int as an position of x and y in random value in sequence
        x = 0;
        y = 0;
        //the logic process = using loop for generate the motion steps in random val
//generate the output
        //map size 10x10
        while(x<10 && y<10){
            // new_x = x;
            // new_y = y;
            cout<< "Posisi Robot:" << x << y << endl;
            x = value(gen);
            y = value(gen);
            langkah+=1;

        }

        cout<< "Robot mencapai batas grid setelah" << langkah << endl;




    }





    private:
    int x;
    int y;
    int new_x;
    int new_y;
    int langkah = 0;


}