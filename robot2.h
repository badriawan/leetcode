#ifndef ROBOT2_H
#define ROBOT2_H

#include<iostream>
#include<vector>//input the using library 
#include<unordered_map>//input the using library 
#include<stack>//input the using library 

using namespace std;

namespace Robot::A{
    template<typename T>
    class robot {
    public:
    robot(vector<T>* v,char &d);
    
    void Print(vector<T>* v, char &d);
    
    
    private:
    void SetVel(vector<T>* v);
    void SetDir(char &d);
    void SaveHist();
    //int v[2];  //velocities of 2 wheels
    vector<int> v;
    stack<int> movestack;
    stack<int> tempstack;

    char d;
    unordered_map<int,string> m ;
    //direction M = forward , B = Back , S = Stop

    };


    template<typename T>
    robot<T>::robot(vector<T>* v,char &d) {

        m[1] = "Forward";
        m[2] = "Backward";
        m[3] = "Stop";

        Print(v,d);
    
    }
    
        // SetVel(v);
        // SetDir(d);
    template<typename T>
    void robot<T>::Print(vector<T>* v, char &d){
        SetVel(v);
        SetDir(d);
        SaveHist();
    }
    template<typename T>
    void robot<T>::SetVel(vector<T>* v){
        cout<< "left velocity = "<<(*v)[0]<<endl;
        cout<< "right velocity = "<<(*v)[1]<<endl;
    }
    template<typename T>
    void robot<T>::SetDir(char &d){
        if(d == 'M'){
            cout<< "The robot move forward"<<endl;
            movestack.push(1);
        }
        else if(d =='B'){
            cout<< "The robot move backward"<<endl;
            movestack.push(2);
        }     
        else if(d == 'S'){
            cout<< "Just stop"<<endl;
            movestack.push(3);
        }
        else{
            cout<< "nothing"<<endl;
        }
    }
    template<typename T>
    void robot<T>::SaveHist(){
        tempstack = movestack;
        cout<< "Movement History :" <<endl;

        while(!tempstack.empty()){
        cout<< m[tempstack.top()] <<endl;
        tempstack.pop();
        }

      
    }
   
    //int v[2];  //velocities of 2 wheels
    //direction M = forward , B = Back , S = Stop
}

#endif


