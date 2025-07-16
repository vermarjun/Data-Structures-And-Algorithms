#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        vector<int> v(n, -1);
        for (auto &it : v) cin>>it;
        sort(v.begin(), v.end());
        for (int i = n-1; i >= 0; i--) cout<<v[i]<<" ";
        cout<<endl;
    }
}