#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>

typedef long long ll;

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n, k; cin>>n>>k;
        vector<int> v(n, 0);
        for (auto &it : v) cin>>it;
        ll sum = 0;
        vector<int> prefix;
        prefix.push_back(0);
        for (int x : v){
            sum+=x;
            prefix.push_back(sum);
        }
        int ans = 0;
        for (int i = 1; i <= n; i++){
            int start_day = i - 1;
            int end_day = (i + k) - 1;
            if (end_day <= n && (prefix[end_day] - prefix[start_day]) == 0){
                ans++;
                i = end_day+1;
            }
        }
        cout<<ans<<endl;
    }
}