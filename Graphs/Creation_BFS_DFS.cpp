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
        // SET THE NODE TO BE VISITED
        visited[src] = true;
        // PRINT THE NODE'S VALUE
        cout<<src<<" ";
        // VISIT ALL THE NEIGHBOUR'S OF THE GIVEN NODE
        for (auto i : g.adjList[src]){
            DFS(i, g, visited);
        }
    }
}

void BFS(char src, Graph<char> g, unordered_map<char,bool> &visited){
    // MAKE A QUEUE
    queue<char> q;
    // QUEUE KE SHURU ME SOURCE NODE PASS KARDE
    q.push(src);
    while (!q.empty()){
        // QUEUE ME SE PEHLI NODE NIKAL LE
        char front = q.front();
        // US NODE KO HATADE QUEUE ME SE
        q.pop();
        // DO ALL THESE ONLY IF NOT VISITED THAT NODE YET
        if (!visited[front]){
            // US NODE KO VISITED = TRUE MARK KARDE
            visited[front] = true;
            // PRINT THE NODE'S VALUE    
            cout<<front<<" ";
            // PUSH ALL NEIGHBOUR'S TO THE QUEUE;
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
    unordered_map<char, bool> visited2;
    BFS('a', g, visited2); // a b d c e f
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
    unordered_map<char, bool> visited3;
    for (char x = 'a'; x < 'h'; x++){
        if (!visited3[x]){
            BFS(x, disconnected, visited3);
        }
    }
}