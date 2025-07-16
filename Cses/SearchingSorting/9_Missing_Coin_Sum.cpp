#include<iostream>
#include<algorithm>
#include<vector>
#include<limits.h>

using namespace std;

bool check(vector<int> v, int mid){
    int j = v.size()-1;
    int ans = 0;
    while(j>=0){
        // cout<<ans<<' '<<mid<<endl;
        if (ans+v[j]<=mid){
            ans+=v[j];
        }
        if (ans == mid) return true;
        j--;
    }
    return false;
}

int main(){
    int h = 0, n; cin>>n;
    vector<int> v;
    for (int i =0; i<n; i++){
        int x; cin>>x;
        h += x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int ans = h+1;
    for (int i = 0; i <= h; i++){
        if (!check(v, i)){
            ans = i;
            break;
        }    
    }
    cout<<ans<<endl;
}