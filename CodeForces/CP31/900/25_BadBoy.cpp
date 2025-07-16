#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int dist(int i, int j, int i1, int j1, int i2, int j2){
    return abs(i-i1) + abs(j - j1) + abs(i2-i1) + abs(j2-j1) + abs(i2-i) + abs(j2-j);
}

int main(){
    int t; cin>>t;
    while (t--){
        int n, m, i, j;
        cin>>n>>m>>i>>j;
        int total_dist = 0;
        vector<pair<int,int>> ans;
        if (dist(1,1 , i, j, n,m) >= total_dist){
            ans.clear();
            ans.push_back({1,1});
            ans.push_back({n,m});
        }
        total_dist = max(total_dist, dist(1,1 , i, j, n,m));
        if (dist(n,1 , i, j, n,m) >= total_dist){
            ans.clear();
            ans.push_back({n,1});
            ans.push_back({n,m});
        }
        total_dist = max(total_dist, dist(n,1 , i, j, n,m));
        if (dist(1,m , i, j, n,m) >= total_dist){
            ans.clear();
            ans.push_back({1,m});
            ans.push_back({n,m});
        }
        total_dist = max(total_dist, dist(1,m , i, j, n,m));
        if (dist(n,1 , i, j, 1,1) >= total_dist){
            ans.clear();
            ans.push_back({n,1});
            ans.push_back({1,1});
        }
        total_dist = max(total_dist, dist(n,1 , i, j, 1,1));
        if (dist(1,m , i, j, 1,1) >= total_dist){
            ans.clear();
            ans.push_back({1,m});
            ans.push_back({1,1});
        }
        total_dist = max(total_dist, dist(1,m , i, j, 1,1));
        if (dist(1,m , i, j, n,1) >= total_dist){
            ans.clear();
            ans.push_back({1,m});
            ans.push_back({n,1});
        }
        for (pair<int,int> p : ans){
            cout<<p.first<<" "<<p.second<<" ";
        }
        cout<<endl;
    }
}