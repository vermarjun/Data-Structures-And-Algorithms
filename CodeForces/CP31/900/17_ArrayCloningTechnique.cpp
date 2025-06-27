#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        vector<int> a(n, -1);
        for (auto &it : a) cin>>it;
        sort(a.begin(), a.end());
        int same = 0, diff = 0; 
        for (int i = 0; i < n; i++){
            int temp = 1;
            while (i < n-1 && a[i] == a[i+1]){
                temp++;
                i++;
            }
            same = max(same, temp);
        }
        diff = n - same;
        long long ans = 0;
        while (diff > 0){
            ans = ans + (long long)min(same, diff) + (long long)1;
            diff-=same;
            same+=same;
        }
        cout<<ans<<endl;
    }
}