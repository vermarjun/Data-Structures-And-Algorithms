#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<math.h>

typedef long long ll;

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n, k; cin>>n>>k;
        vector<int> v(n, -1);
        for (auto &it : v) cin>>it;
        int curr_height = v[k-1];
        sort(v.begin(), v.end());
        int curr_water_level = 1;
        int heighest_tower = v[n-1];
        bool ans = true;
        for (int i = (find(v.begin(), v.end(), curr_height) - v.begin()); i < n; i++){
            // cout<<i<<" updated_i: ";
            while (i < n-1 && v[i] == v[i+1]) i++;
            // cout<<i<<endl;
            if (i < n-1 && (v[i] - curr_water_level) + 1 < v[i+1] - v[i]){
                ans = false;
                break;
            }
            if (i < n-1){
                curr_water_level = curr_water_level + (v[i+1]-v[i]); 
            }           
        }
        ans? cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
}