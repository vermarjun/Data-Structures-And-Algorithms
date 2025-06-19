#include<iostream>
#include<list>
#include<unordered_map>
#include<map>
#include<stack>
#include<vector>

using namespace std;

// Weighted Graph Can not use BFS here
// SSSP Algorithm: single source shortest path algo
class Graph {
public:
    unordered_map<int, list<pair<int,int>>> adjList;
    void addEdge(int u, int v, int wt, bool direction){
        if (direction){
            adjList[u].push_back({v,wt});
        }
        else {
            adjList[v].push_back({u,wt});
            adjList[u].push_back({v,wt});
        }
    }
    void printEdges(){
        for (auto element : adjList){
            cout<<element.first<<" : {";
            for (pair<int,int> x : element.second){
                cout<<"{ "<<x.first<<" , "<<x.second<<" }, ";
            }
            cout<<"}"<<endl; 
        }
    }
    void topoSort(int src ,stack<int> &st, unordered_map<int, bool> &vis){
        for (auto x : adjList[src]){
            if (!vis[x.first]){
                vis[x.first] = true;
                topoSort(x.first, st, vis);
            }
        }
        st.push(src);
    }
    void sssp(int dest, stack<int> &st, vector<int,int> &distanceArray){    
        // TOPOLOGICAL ORDERING ME PEHLI NODE HI SRC HOGI!!!;
        int src = st.top();
        st.pop();
        distanceArray[src] = 0;

        for (auto x : adjList[src]){
            
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0, 1, 5, 1);
    g.addEdge(0, 2, 3, 1);
    g.addEdge(2, 4, 6, 1);
    g.addEdge(2, 3, 5, 1);
    g.addEdge(2, 1, 2, 1);
    g.addEdge(1, 3, 3, 1);
    g.addEdge(4, 3, 1, 1);
    cout<<"Print EdgeList: "<<endl;
    g.printEdges();

    unordered_map<int, bool>vis;
    stack<int> st;
    int src = 0;
    vis[src] = true;
    g.topoSort(src, st, vis);
    // unordered_map<int, bool>visited;
    vector<int,int> distanceArray;
}