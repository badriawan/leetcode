#include <iostream>
#include <vector>

using namespace std;

int binarySearch(const vector<double>& sensorArray,int size,double target){
    int left = 0;
    int right = size - 1;
    int mid;

    while(left<=right){
        mid = left + (right-left)/2;
    
    if(target==sensorArray[mid]){
        return mid;
    }
    else if(target<sensorArray[mid]){
        right = mid - 1;
    }
    else{
        left = mid + 1;
    }

    }

    return -1;

}

int main(){
    vector<double> sensor = {0.5 , 0.6 , 0.7};
    int a = binarySearch(sensor,sensor.size(),0.5);
    cout<<"The index is "<< a << endl;
    return 0;
}