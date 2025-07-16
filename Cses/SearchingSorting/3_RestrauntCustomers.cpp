#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>
#include<queue>
using namespace std;

int main(){
    int n = 0;
    cin>>n;
    vector<pair<int,int>> v;
    for (int i = 0; i < n; i++){
        int a = 0, b = 0; cin>>a>>b;
        v.push_back({a,b});
    }  
    sort(v.begin(), v.end());
    int i = 0, j = 0;
    int ans = 1;
    int currentCustomers = 1;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (pair<int,int> x : v){
        if (pq.empty()){
            pq.push(x.second);
        }
        else {
            while(!pq.empty() && pq.top()<x.first){
                pq.pop();
            }
            pq.push(x.second);
            int size = pq.size(); 
            ans = max(ans, size);
        }
    }
    cout<<ans<<endl;
}