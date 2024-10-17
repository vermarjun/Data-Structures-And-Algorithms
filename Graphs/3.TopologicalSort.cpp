#include<iostream>
#include<stack>
#include<unordered_map>
#include<map>
#include<list>
#include<queue>

using namespace std;

class Graph {
public:
    unordered_map<int, list<int>> adjList;
    void addEdge(int u, int v, bool direction){
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
            for (int y : x.second){
                cout<<y<<", ";
            }
            cout<<" }"<<endl;
        }
    }
    void topoSortDfs(int src ,unordered_map<int, bool> &vis, stack<int> &st){
        vis[src] = true;
        for (int x : adjList[src]){
            topoSortDfs(x, vis, st);
        }
        st.push(src);
    }
    void topoSortBfs(){
        unordered_map<int, int> inDegree;
        for (auto x : adjList){
            for (int y : x.second){
                inDegree[y]++;
            }
        }
        queue<int> q;
        for (auto x : adjList){
            if (inDegree[x.first] == 0){
                q.push(x.first);
            }
        }
        while(!q.empty()){
            int frontNode = q.front();
            q.pop();
            cout<<frontNode<<" ";
            for (int x : adjList[frontNode]){
                inDegree[x]--;
                if (inDegree[x] == 0){
                    q.push(x);
                }
            }
        }
    }
};

int main(){
    Graph g;
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 1);
    g.addEdge(3, 5, 1);
    g.addEdge(4, 6, 1);
    g.addEdge(6, 7, 1);

    cout<<"Printing Edge List: "<<endl;
    g.printEdges();
    
    // TIME COMPLEXITY OF TOPOSORT IS SAME AS dfs!
    unordered_map<int, bool> vis;
    stack<int> st;
    g.topoSortDfs(0, vis, st); // This will break if we have disconnected Components. Wrap this in for loop to iterate through all components!;
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    cout<<endl;
    g.topoSortBfs();
    cout<<endl;
}