#include<iostream>
#include<unordered_map>
#include<list>
#include<queue>

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
    void printEdges(){
        for (auto x : adjList){
            cout<<x.first<<" : {";
            for (auto element : x.second){
                cout<<element<<" ,";
            }
            cout<<" }"<<endl;
        }
    }
    void shortestPathUsingBFS(int src, int dest){
        unordered_map<int, bool> visited;
        unordered_map<int, int> parent;
        queue<int> q;
        q.push(src);
        visited[src] = true;
        parent[src] = -1;
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            for (int x : adjList[frontNode]){
                if (!visited[x]){
                    q.push(x);
                    visited[x] = true;
                    parent[x] = frontNode;
                }
            }
        }
        vector<int> path;
        while(dest!=-1){
            path.push_back(dest);
            dest = parent[dest];
        }
        for (int x : path){
            cout<<x<<" ";
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 5, 1);
    g.addEdge(0, 3, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(0, 4, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(6, 5, 1);

    g.printEdges();
    g.shortestPathUsingBFS(0, 5);
}