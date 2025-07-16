#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        vector<int> s(n, -1);
        for (auto &it : s) cin>>it;
        vector<int> ans(n, -1);
        for (int i = 0; i < n; i++) ans[i] = i + 1; 
        for (int i = 0; i < n-1; i++){
            if (s[i] == s[i+1]){
                swap(ans[i], ans[i+1]);
            }
        }
        for (int i = 0; i < n; i++){
            if (ans[i] == i + 1){
                ans.clear();
                ans.push_back(-1);
                break;
            }
        }
        for (int x : ans) cout<<x<<" ";
        cout<<endl;
    }
}