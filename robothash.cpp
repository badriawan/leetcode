#include <iostream>



//1.define the class, method and variables
//2.define the logic based on input and output
using namespace std;

class Robotmap{
    public:
    robotmap();
    unordered_map<pair<int, int>, int, pair_hash> terrainMap;
    
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator() (const std::pair<T1, T2>& pair) const        {
            return std::hash<T1>()(pair.first) ^ std::hash<T2>()            (pair.second);
        }
    };

    unordered_map<int,string> terrain =
    {
        {0,"Jalan Biasa"},
        {1,"Lumpur"},
        {2,"Bukit"},
        {3,"Air"}
    }; //terrain[int i]
    
    //when get an input of grid maps and type of terrain, save to variables grid
    void SetTerrain(x,y,terrain){
        
        vector<int>* grid = new vector<int>{x,y,terrain};
        
        
        
    }
    
    void GetTerrain(x,y){
        
        
        terrain 
        
        
        cout<< "Terrain at" << x << y << : << terrain << endl;
        
        
        
    }
    
    
    
    private:
    int x;
    int y;
    int terrain;
    
    
    
    
    
};


int main(){
  Robotmap a;
  a.SetTerrain();  
    
    
    
}