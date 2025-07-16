#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

int main(){
    int n = 0; cin>>n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int x = 0; cin>>x;
        v.push_back(x);
    }
    int i = 0, j = 0;
    long long x = 0;
    long long ans = INT_MIN;
    while (i<n && j<n){
        if (i == j){
            x = v[i];
        }
        else {
            x+=v[j];
        }
        if (x<0){
            i = j+1;
        }
        j++;
        if (x>ans) ans = x;
    }
    cout<<ans<<endl;
}