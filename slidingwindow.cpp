// #include "rosbot_class.hpp"
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Sliding 
{
    public:
    Sliding(){}

        
    void Process(vector<int>& is_array){
      //get the input

      //processing input with logic 
      //remove the previous left sub element by substraction and add the new next sub element by sum.
      int a = is_array.size();
      sub_array = is_array[0]+is_array[1]+is_array[2];
      max_sum = sub_array;
      //new_array.push_back(sub_array);
      for(int i = 1;i<a-2;i++){
        sub_array = sub_array-is_array[i-1]+is_array[i+2];
        max_sum = max(max_sum,sub_array); //compare the max previous with the new value
        cout << "sub array " << sub_array << endl;
        //new_array.push_back(sub_array);

      }

      //int max_sum = *std::max_element(new_array.begin(),new_array.end());

      cout << "nilai sub maks " << max_sum << endl;

    }    


    private:
    int sub_array;
    vector<int> new_array = {};
    int max_sum;



};

int main(int argc, char **argv) {
  Sliding S;
  vector<int> array = {2,3,5,1,6,2,8,4};
  S.Process(array);
  return 0;
}