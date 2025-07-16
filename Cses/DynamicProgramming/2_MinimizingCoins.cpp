#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

int solve(vector<int> &dp, vector<int> &coins, int x){
    if (x < 0) return INT_MAX;
    if (x == 0) return 0;
    if (dp[x] != -1) return dp[x];
    int ans = INT_MAX;
    for (int i = 0; i < coins.size(); i++){
        int coins_req = solve(dp, coins, x-coins[i]);
        if (coins_req != INT_MAX){
            ans = min(coins_req+1, ans);
        }
    }
    return dp[x] = ans;
}

int main(){
    int n, x; cin>>n>>x;
    vector<int> coins(n, -1);
    for (auto &it : coins) cin>>it;
    vector<int> dp(x+1, -1);
    int ans = solve(dp, coins, x);
    if (ans == INT_MAX) ans = -1;
    cout<<ans<<endl;
}