#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n, m; cin>>n>>m;
        vector<vector<int>> mat(n, vector<int> (m, -1));
        for (auto &v : mat){
            for (auto &it : v) cin>>it;
        }
        int negative = false;
        int mini = INT_MAX;
        long long ans = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < m; j++){
                mini = min(abs(mat[i][j]), mini);
                if (mat[i][j] < 0) negative++; 
                ans+=abs(mat[i][j]);
            }
        }
        if (negative > 0 && negative % 2 != 0){
            ans = ans - (2 * mini);
        }
        cout<<ans<<endl;
    }
}