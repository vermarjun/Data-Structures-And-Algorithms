#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        ll w, h; cin>>w>>h;
        ll ans = 0;
        for (int i = 0; i < 4; i++){
            int k; cin>>k;
            vector<int> v(k, -1);
            for (auto &it : v) cin>>it;
            ll area = 0;
            if (i < 2){
                area = ll(abs(v[0] - v[k-1])) * h;
            } else {
                area = ll(abs(v[0] - v[k-1])) * w;
            }
            ans = max(area, ans);
        }
        cout<<ans<<endl;
    }
}