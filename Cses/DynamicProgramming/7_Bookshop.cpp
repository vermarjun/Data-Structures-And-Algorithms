#include<iostream>
#include<vector>

using namespace std;

int solve(vector<vector<int>> &dp, vector<int> &pages, vector<int> &prices, int money, int index, int n){
    if (index >= n || money <= 0) return 0;
    if (dp[index][money] != -1) return dp[index][money];
    int inclusion = 0;
    if (money >= prices[index]){
        inclusion = solve(dp, pages, prices, money - prices[index], index+1, n) + pages[index];
    }
    int exclusion = solve(dp, pages, prices, money, index+1, n) + 0;
    return dp[index][money] = max(inclusion, exclusion);
}

int main(){
    int n, money; cin>>n>>money;
    vector<int> prices(n), pages(n);
    for (auto &it : prices) cin>>it;
    for (auto &it : pages) cin>>it;
    vector<vector<int>> dp(n+1, vector<int> (money+1, -1));
    cout<<solve(dp, pages, prices, money, 0, n)<<endl;
}