#include<iostream>
#include<vector>
#include<math.h>
#include<string>

using namespace std;

const int mod = 1e9 + 7;

long long solve(vector<long long> &dp, int n){
    if (dp[n] != -1) return dp[n];
    long long ans = 0;
    for (int i = 1; i <= 6; i++){
        if (n - i > 0){
            ans+=solve(dp, n-i);
        } else if (n - i == 0){
            ans++;
        }
        if (ans >= mod) ans = ans % mod;
    }
    return dp[n] = ans;
}

int main(){
    int n; cin>>n;
    vector<long long> dp(n+1, -1);
    cout<<solve(dp, n)<<endl;
}