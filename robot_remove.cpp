#include <iostream>
#include <vector>
#include <utility>
#include <array>


//define all of the libraries and variables need
using namespace std;

class Remove{
    public:
    Remove(){}
    //analyze the input needed = array as input
    // array = [{x,y} , {x,y}]
    void Input(int x, int y){

        array.push_back(make_pair(x,y)); 

    }

    vector<pair<int,int>> Output(){
        
        //sort(array.begin(),array.end());
        int j = 0;
        for(int i=1;i < array.size();i++){
                if(array[i] != array[i-1]){
                    array[j] = array[i];
                    j++;
                }
        return array;

        }
        }
    //cout << array << endl;

    

    private:
    vector<pair<int,int>> array;



};

int main() {
    //define the object
    Remove w;
    w.Input(1,2);
    w.Input(4,2);
    w.Input(1,2);

    vector<pair<int,int>> a = w.Output();
    
    if(!a.empty()){
    for(auto i:a){    
    cout << i.first << i.second << endl;
    }
    }//new array  = [{x,y} , {x,y}] without double


    return 0;
}