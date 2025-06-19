#include<iostream>
#include<unordered_map>
#include<string.h>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>

using namespace std;

template <typename T>

// UNWEIGHTED GRAPH:
class Graph{
public:
    unordered_map<T, list<T>> adjList;
    void addEdge(T u, T v , bool direction){
        if (direction){
            // direction == 1 => directed edge => u->
            // u -> v if directed 
            adjList[u].push_back(v);
        }
        else {
            // direction == 0 => undirected edge => u--v
            // u->v 
            adjList[u].push_back(v);
            // v->u 
            adjList[v].push_back(u);
        }
        // cout<<"Printing adjList: "<<endl;
        // printAdjList();
    }
    void printAdjList(){
        for (auto node : adjList){
            cout<<node.first<<"-> {";
            for (auto neighour : node.second){
                cout<<neighour<<", ";
            }
            cout<<"}"<<endl;
        }
    }
    void BFS(T src, unordered_map<char , bool> &visited){
        queue<T> q;
        q.push(src);
        visited[src] = true;
        while (!q.empty()){
            char front = q.front();
            cout<<front<<" ";
            q.pop();
            for (int x : adjList[front]){
                if (!visited[x]){
                    q.push(x);
                    visited[x] = true;
                }
            }
        }
    }
    void DFS(T src, unordered_map<char,bool> &visited){
        visited[src] = true;
        cout<<src<<" ";
        for (auto nbr : adjList[src]){
            if (!visited[nbr]){
                DFS(nbr, visited);
            }
        }
    }
};
// WEIGHTED GRAPH:
class GraphWt{
public:
    unordered_map<int,list<pair<int,int>>> adjList;
    void addEdge(int u, int v, int wt, int direction){
        if (direction == 1){
            adjList[u].push_back({v, wt});
        }
        else {
            adjList[u].push_back({v, wt});
            adjList[v].push_back({u, wt});
        }
        // cout<<"Printing adjList: "<<endl;
        // printAdjList();
    }
    void printAdjList(){
        for (auto i : adjList){
            cout<<i.first<<" -> {";
            for (auto list : i.second){
                cout<<"{"<<list.first<<" ,"<<list.second<<"}";
            }
            cout<<"}"<<endl;
        }
    }
};


int main(){
    Graph<char> g;
    g.addEdge('a', 'b', 0);
    g.addEdge('b', 'c', 0);
    g.addEdge('a', 'd', 0);
    g.addEdge('d', 'e', 0);
    g.addEdge('e', 'f', 0);
    g.addEdge('d', 'f', 0);
    /*
        a
       / \
      b   d --\ 
     /     \   \
    c       e - f
    */
    GraphWt g2;
    g2.addEdge(1, 2,28, 1);
    g2.addEdge(2, 3, 30 , 1);
    g2.addEdge(1, 4, 50, 1);
    
    
    unordered_map<char , bool> visited;
    unordered_map<char , bool> visited2;
    g.DFS('a', visited2);
    cout<<endl;
    g.BFS('a', visited); // Disconnected graph ke case me fat jayega
    cout<<endl;
    // SOLUTION? we pass all nodes to BFS and not just source node 'a' while also checking if visited is true don't call BFS for it else do call BFS for it
    // Disconnected graph
    Graph<char> disconnected;
    disconnected.addEdge('a', 'b', 0);
    disconnected.addEdge('b', 'c', 0);

    disconnected.addEdge('d', 'e', 0);
    
    disconnected.addEdge('f', 'h', 0);
    
    unordered_map<char, bool> visited3;
    for (char node = 'a'; node<='f'; node++){
        if (!visited3[node]){
            disconnected.BFS(node,visited3);
        }
    }
}