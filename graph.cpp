#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Graph{
    public:
    Graph(){}
    unordered_map<int,vector<int>> node;
        
    void addEdge(int j,int v){

        node[j].push_back(v);


    }

    void printGraph(){
        for (auto& pair : node){

            cout << pair.first << endl;
            for (auto& n : pair.second){

                cout << n << endl;

            }
        }

    }

};

int main(){
    Graph graph;

    // Tambahkan edges
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);

    // Cetak graph
    cout << "Adjacency List dari Graph:" << endl;
    graph.printGraph();

    return 0;



}

