#include<iostream>
#include<vector>

typedef long long ll;

using namespace std;

// NO LOGIC EASIEST QUESTION LEETCODE TYPE QUESTION WITH PURE IMPLEMENTATION OF PREFIX SUM

int main(){
    int t; cin>>t;
    while (t--){
        int n, q; cin>>n>>q;
        vector<ll> a(n, -1);
        for (auto &it : a) cin>>it;
        vector<ll> prefix;
        ll sum = 0;
        prefix.push_back(sum);
        for (auto &it : a) {
            sum+=it;
            prefix.push_back(sum);
        };
        while (q--){
            int l, r, k; cin>>l>>r>>k;
            ll sub_sum = prefix[r] - prefix[l-1];
            ll new_sum = sum - sub_sum + (r-l+1)*k;
            if (new_sum % 2 == 0) {
                cout<<"NO"<<endl;
            } else {
                cout<<"YES"<<endl;
            }
        }
    }
}