#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>

using namespace std;

int main(){
    int n, d; cin>>n>>d;
    vector<int> v(n, -1); 
    for (auto &it : v) cin>>it;
    sort(v.begin(), v.end());
    int players = n;
    int ans = 0;
    for (int i = n-1; i >= 0; i--){
        double heighest_power = v[i];
        double players_req = ceil((d + 1.00) / heighest_power);
        if (players_req > players) break;
        players-=players_req;
        ans++;
    }
    cout<<ans<<endl;
}