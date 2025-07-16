#include<iostream>
#include<vector>
#include<algorithm>
#include<limits.h>

using namespace std;

int main(){
    int n, x; cin>>n>>x;
    vector<int> v;
    for (int i= 0; i < n; i++){
        int x; cin>>x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i= 0; i < n; i++){
        if (v[i] == -1) continue;
        int j = n-1;
        while(j>i && (v[j] == -1 || v[i]+v[j]>x)){
            j--;
        }
        if (j>i) v[j] = -1;
        v[i] = -1;
        ans++;
    }
    cout<<ans<<endl;
}