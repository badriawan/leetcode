#include "primenumber.h"

using namespace std;


bool PrimeNumber::Process(int a){
        
        if(a<2){return false; }
        if(a<=3){return true; }
        if(a==5){return true; }


        if(a%2==0 || a%3==0 || a%5==0 ){
            return false;
        }
        else{

            return true;
        }


    }

int main(){

    PrimeNumber p;
    bool w = p.Process(8);
    if(w==true){
        cout<< "Prime Number"<<endl;
    }
    else{

        cout<<"Not Prime Number"<<endl;

    }

}