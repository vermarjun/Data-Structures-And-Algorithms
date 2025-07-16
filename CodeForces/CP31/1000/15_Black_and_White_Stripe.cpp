#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n, k; cin>>n>>k;
        string s; cin>>s;
        int total_w = 0;
        vector<int> prefix;
        prefix.push_back(0);
        for (int i = 0; i < n; i++){
            if (s[i] == 'W') total_w++;
            prefix.push_back(total_w);
        }
        int ans = INT_MAX;
        for (int i = 1; i <= (n-k)+1; i++){
            int curr_w = prefix[i+k-1] - prefix[i-1];
            ans = min(ans, curr_w);       
        }
        cout<<ans<<endl;
    }
}