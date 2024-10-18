#include <iostream>
#include <vector>
//define all of the libraries and variables need
using namespace std;

class Weight{
    public:
    Weight(){}
    //analyze the input needed = array as input
    vector<int> Process(vector<int>&weights, int target_weight){
        //int a[] = {1,2,3};
        //define the logic , get the array variables and compare it
        for(int i=0;i < weights.size();i++){
            for(int j=i+1;j < weights.size();j++){
            if((weights[i] + weights[j]) == target_weight){
                return {i,j};
            }
        }
        }

    return{};



    }



};

int main() {
    Weight w;
    vector<int> weights = {2,7,4};
    vector<int> result = w.Process(weights,9);
    if(!result.empty()){
    cout<< result[0] << result[1];
    }
    else{
        cout<<"nope";
    }
    return 0;
}