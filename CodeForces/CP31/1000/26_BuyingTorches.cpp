#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        long long x, y, k; cin>>x>>y>>k;
        long long sticks_for_coal = y * k;
        long long sticks_for_torches = k;
        long long total_sticks_required = sticks_for_coal + sticks_for_torches - 1;
        long long ans = floor(((long double)total_sticks_required)/(long double)(x - 1.00));
        // cout<<" total_sticks_required: "<<total_sticks_required<<" ans: "<<ans<<" comp: "<<total_sticks_required % (ans * (x-1))<<endl;
        if (ans == 0 || total_sticks_required % (ans * (x-1)) >= 1) ans++;
        ans+=k;
        cout<<ans<<endl;
    }
}