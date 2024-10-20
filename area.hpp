#ifndef AREA_HPP
#define AREA_HPP


//import the libraries



using namespace std;


//define the class and variables

class Circle{
    public:
    Circle(int r){
       Area(r);
    }

    void Area(int r);

    private:
    double pi = 3.14;

    //define the logic = pi *r*r
    
};

class Triangle{
    public:
    Triangle(int l,int h){
        Area(l,h);
    }
    //define the logic = l*h/2
    void Area(int l,int h);

   

};

class Square{
    public:
    Square(int l,int w){
        Area(l,w);
    }
    void Area(int l,int w);



};




#endif