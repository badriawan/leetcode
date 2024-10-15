#include <iostream>
#include <unordered_map>
#include <string>



//1.define the class, method and variables
//2.define the logic based on input and output
using namespace std;

class Robotmap{
    public:
    //Robotmap();
    
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2>& pair) const{
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()(pair.second);
        }
    };

    unordered_map<pair<int, int>, int, pair_hash> terrainMap;


    //when get an input of grid maps and type of terrain, save to variables grid
    void SetTerrain(int x,int y,int int_terrain){
        terrainMap[{x,y}] = int_terrain;
    }
    
    string GetTerrain(int x,int y){
        //if( terrainMap.find({x,y}) != terrainMap.end()){
        int t = terrainMap[{x,y}];
        switch(t){
            case 0: return "Jalan Biasa";
            case 1: return "Lumpur";
            case 2: return "Bukit";
            case 3: return "Air";
            default: return "nope";
        } 
        }   
        
    };


int main(){
  Robotmap a;
  a.SetTerrain(2,2,1);
  cout<< "Terrain pada posisi 2,2 adalah" << a.GetTerrain(2,2);  
    
  return 0;
    
}