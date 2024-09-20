#include<iostream>
#include<unordered_map>
#include<string.h>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>

using namespace std;

template <typename T>

class Graph{
    public:
        unordered_map<T, list<T>> adjList;
        void addEdge(T u, T v , bool direction){
            // u -> v if directed 
            // u->v and v->u if undirected!
            // direction is  0 if directed and 1 if undirected
            if (direction){
                adjList[u].push_back(v);
            }
            else {
                adjList[u].push_back(v);
                adjList[v].push_back(u);
            }
        }
};

void DFS(char src, Graph<char> g, unordered_map<char,bool> &visited){
    if (!visited[src]){
        visited[src] = true;
        cout<<src<<" ";
        for (auto i : g.adjList[src]){
            DFS(i, g, visited);
        }
    }
}

void BFS(char src, Graph<char> g, unordered_map<char,bool> visited){
    queue<char> q;
    q.push(src);
    while (!q.empty()){
        char front = q.front();
        visited[front] = true;
        q.pop();
        if (!visited[front]){
            cout<<front<<" ";
            for (int x : g.adjList[front]){
                if (!visited[x]){
                    q.push(x);
                }
            }
        }
    }
}

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
    // DFS TO PRINT THE GRAPH:
    // will have to create a visited data structure to make sure i don't print same node twice because there could be circular connections in a graph unlike bt or bst
    unordered_map<char, bool> visited;
    DFS('a' , g, visited); // a b c d e f
    cout<<endl;
    unordered_map<char, bool> visited12;
    BFS('a', g, visited12); // a b d c e f
    cout<<endl;

    // These DFS BFS won't work on disconnected graphs, to work with disconnected graph, gotta use for loop to iterate on each character;

    Graph<char> disconnected;
    disconnected.addEdge('a', 'b', 0); 
    disconnected.addEdge('a', 'c', 0); 
    disconnected.addEdge('b', 'c', 0); 
    
    disconnected.addEdge('d', 'e', 0); 
    disconnected.addEdge('e', 'f', 0);

    disconnected.addEdge('g', 'h', 0); 
    // We have 3 disconnected components of graphs here!
    unordered_map<char, bool> visited2;
    for (char x = 'a'; x<'h'; x++){
        if (!visited2[x]){
            visited2[x] = true;
            BFS(x, disconnected, visited2);
        }
    }
}