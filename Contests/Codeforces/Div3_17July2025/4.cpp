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
        ll n, k; cin>>n>>k;
        vector<vector<ll>> casino(n, {-1,-1,-1});
        for (auto &v : casino){
            for (int i = 0; i < 3; i++) cin>>v[i];
        }
        sort(casino.begin(), casino.end());
        for (int i = 0; i < n; i++){
            if (k >= casino[i][0] && k <= casino[i][1] && casino[i][2]>k) k = casino[i][2];
        }
        cout<<k<<endl;
    }   
}