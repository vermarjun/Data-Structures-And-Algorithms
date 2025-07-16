#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n, x; cin>>n>>x;
        vector<int> a(n, -1);
        for (auto &it : a) cin>>it;
        int left = a[0]-x;
        int right = a[0]+x;
        int ans = 0;
        for (int i = 1; i < n; i++){
            int curr_left = a[i] - x;
            int curr_right = a[i] + x;
            left = max(left, curr_left);
            right = min(right, curr_right);
            if (right < left) {
                ans++;
                left = a[i] - x;
                right = a[i] + x;
            }
        }
        cout<<ans<<endl;
    }
}