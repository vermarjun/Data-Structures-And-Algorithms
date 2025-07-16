#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        vector<pair<int,int>> v(n, {0,0});
        for (int i = 0; i < n; i++){
            cin>>v[i].first;
            v[i].second = i;
        }
        vector<long long> ans(n+1, -1);
        sort(v.begin(), v.end());
        long long hq_position = ceil((n+1)/2.00);
        ans[0] = hq_position;
        long long x = 1;
        long long cost = 0;
        for (int i = n-1; i >= 0; i-=2){
            ans[v[i].second+1] = hq_position-x;
            cost = cost + 2 * (x) * (long long)(v[i].first);
            if (i-1>=0){
                ans[v[i-1].second+1] = hq_position+x;
                cost = cost + 2 * (x) * (long long)(v[i-1].first);
            }
            x++;
        }
        cout<<cost<<endl;
        for (int ai : ans) cout<<ai<<" ";
        cout<<endl; 
    }
}