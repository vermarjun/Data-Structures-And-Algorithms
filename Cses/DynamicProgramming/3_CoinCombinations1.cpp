#include<iostream>
#include<vector>
#include<limits.h>
#include<algorithm>

using namespace std;

int mod = 1e9 + 7;

long long solve(vector<int> &dp, vector<int> &coins, int x){
    if (x < 0) return 0;
    if (x == 0) return 1;
    if (dp[x] != -1) return dp[x];
    long long ans = 0;
    for (int i = 0; i < coins.size() && coins[i] <= x; i++){
        long long coins_req = solve(dp, coins, x-coins[i]);
        ans+=coins_req;
        if (ans >= mod) ans = ans % mod;
    }
    return dp[x] = ans;
}

int tabulation(vector<int> &coins, int x){
    vector<int> dp(x+1, -1);
    // init
    dp[0] =  1;
    long long ans = 0;
    // x ke upar konsa loop chalaun ye nahi samajh aa raha mujhe is question me FUCCKKKKKKKKKK
}

int main(){
    int n, x; cin>>n>>x;
    vector<int> coins(n, -1);   
    for (auto &it : coins) cin>>it;
    vector<int> dp(x+1, -1);
    sort(coins.begin(), coins.end());
    long long ans = solve(dp, coins, x);
    cout<<ans<<endl;
}