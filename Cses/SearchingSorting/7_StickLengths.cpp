#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

int main(){
    int n = 0; cin>>n;
    vector<int> sticks;
    for (int i = 0; i < n; i++){
        int x = 0; cin>>x;
        sticks.push_back(x);
    }   
    sort(sticks.begin(), sticks.end());
    long long ans = 0;
    int midHeight = sticks[n/2];
    for (int x : sticks){
        ans+= abs(x - midHeight);
    }
    cout<<ans<<endl;
}