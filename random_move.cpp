#include <iostream>
#include <random>

//define all of the libraries and variables need
using namespace std;
//analyze the input needed = no input

class Position{
    public:
    Position():gen(rd()),value(0, 2){}
    
    // the output is random position of x and y 
    void output(){
        //lets define the int as an position of x and y in random value in sequence
        x = 0;
        y = 0;
        xt = 0;
        yt = 0;
        
        //0 straight , 1 left , 2 right
        
        //the logic process = using loop for generate the motion steps in random val
//generate the output
        //map size 10x10
        while(x<10 && y<10){
            int a = value(gen);
            cout<< "Posisi Robot:" << x << y << endl;
            cout<< a << endl;

            
            switch(a){
                case 0:
                xt+=1;
                yt+=1;
                break;
                case 1:
                xt+=1;
                yt;
                break;
                case 2:
                xt;
                yt+=1;
                break;
            };
            x = xt;
            y = yt;
            langkah+=1;

        }

        cout<< "Robot mencapai batas grid setelah" << langkah << endl;




    }





    private:
    int x;
    int y;
    int xt;
    int yt;
    int langkah = 0;
    random_device rd;
    mt19937 gen;
    uniform_int_distribution<> value;


};

int main() {
    Position pos;
    pos.output();
    return 0;
}