#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>

using namespace std;

class Action{
    public:
    Action(){}
    unordered_map<string,int> m;

    
    void commandList (string c){
        if(c=="Forward"){
            //m[c] = 1;
            q.push("Forward");
        }
        else if(c=="Backward"){
            //m[c] = 1;
            q.push("Backward");
        }
        else{
            cout << "error command list" <<endl;
        }
     
     
    



    }

    void executeCommand(){
        // for(int i:q){
        //      cout<< "The robot move " << q.front()<<endl;
        //      q.pop();

        // }

        while(!q.empty()){
            cout<< "The robot move " << q.front()<<endl;
            q.pop();
        }

    }


    private:
    queue<string> q;

};



int main(){
    Action a;
    a.commandList("Forward");
    a.commandList("Backward");

    a.executeCommand();

    return 0;


}