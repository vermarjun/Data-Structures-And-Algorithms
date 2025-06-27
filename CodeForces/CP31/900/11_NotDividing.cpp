#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        vector<int> v(n, -1);
        for (auto &it : v) cin>>it;
        if (n >= 2){
            for (int i = 0; i < n-1; i++){
                if (v[i] == 1){
                    v[i]+=1; 
                    if (v[i+1] % 2 == 0){
                        v[i+1]+=1;
                    }
                } else {
                    // at most 2n operations!?
                    while (v[i+1] % v[i] == 0) v[i+1]+=1;
                }
            }
        }
        for (int x : v) cout<<x<<" ";
        cout<<endl;
    }
}