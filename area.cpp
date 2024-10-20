//import the libraries
#include "area.hpp"

using namespace std;


void Circle::Area(int r){
    double area = pi * pow(r,2); 
    cout << "The area of the circle is" << area << endl;
}
//define the class and variables

void Triangle::Area(int l,int h){
        double area = (l * h)/2; 
        cout << "The area of the triangle is" << area << endl;
}

 //define the logic = l*w
void Square::Area(int l,int w){
        double area = l*w; 
        cout << "The area of the square is" << area << endl;
    }



int main(){

    //create the object and argument as an input
    Circle C(7);
    Triangle T(10,2);
    Square S(10,2);


}