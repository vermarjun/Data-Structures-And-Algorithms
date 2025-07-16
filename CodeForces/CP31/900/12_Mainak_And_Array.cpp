#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        vector<int> v(n,-1);
        for (auto &it : v) cin>>it;
        int maxi = 0; int mini = 0;
        int ans = 0;
        for (int i = 0; i < n; i++){
            if (v[maxi] <= v[i]){
                maxi = i;
            }
            if (v[mini] >= v[i]){
                mini = i;
            }
            if (i == n-1){
                ans = max(ans, v[i]-v[0]);
            } else {
                ans = max(ans, v[i] - v[i+1]);
            }
        }
        ans = max(ans, max(v[maxi] - v[0], v[n-1] - v[mini]));
        cout<<ans<<endl;
    }
}