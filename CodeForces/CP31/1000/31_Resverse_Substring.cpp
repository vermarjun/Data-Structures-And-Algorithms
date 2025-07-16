#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    int n; cin>>n;
    string s; cin>>s;
    vector<int> prefix(n, -1);
    int curr_min = n-1;
    for (int i = n-1; i >= 0; i--){
        if (s[curr_min] >= s[i]) curr_min = i;
        prefix[i] = curr_min;
    }
    for (int i = 0; i < n; i++){
        // cout<<prefix[i]<<" s[prefix[i]]: "<<s[prefix[i]]<<" s[i]: "<<s[i]<<endl;
        if (s[prefix[i]] < s[i]){
            cout<<"YES"<<endl;
            cout<<i+1<<" "<<prefix[i]+1<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;
}   