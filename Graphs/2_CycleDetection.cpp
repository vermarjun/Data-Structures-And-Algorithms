#include<iostream>
#include<vector>
#include<unordered_map>
#include<map>
#include<queue>
#include<list>

using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v, int direction){
        if (direction){
            adjList[u].push_back(v);
        }
        else {
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
    }    
    void printEdge(){
        for (auto x : adjList){
            cout<<x.first<<" : {";
            for (auto element : x.second){
                cout<<element<<" ,";
            }
            cout<<" }"<<endl;
        }
    }
    // we have 4 ways of cycle detection:
    // 1) In directed graph using bfs or dfs
    // 2) In undirected graph using bfs or dfs
    bool directedDfs(int src ,unordered_map<int,bool> &visited){
        if (visited[src]) return true;
        visited[src] = true;
        for (int x : adjList[src]){
           bool alreadyVisited = directedDfs(x, visited);
           if (alreadyVisited) return alreadyVisited;
        }
        visited[src] = false;
        return false;
    }
    void directedBfs(){

    }
    void undirectedDfs(){

    }
    void undirectedBfs(){

    }
};

int main(){
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(4, 2, 1);
    g.addEdge(4, 5, 1);

    cout<<"Printing adjList: "<<endl;
    g.printEdge();

    unordered_map<int, bool> visited;
    cout<<g.directedDfs(0 ,visited)<<endl;
}