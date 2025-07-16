#include<iostream>

typedef long long ll;

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        ll n, k, x; cin>>n>>k>>x;
        ll z = (n * (n+1))/2;
        ll y = (k * (k+1))/2;
        bool ans = true;
        if (x < y) ans = false;
        if (x > z) ans = false;
        ll w = (k * ((2 * n) - k + 1))/2;
        // cout<<"X: "<<x<<" Y: "<<y<<" Z: "<<z<<" W: "<<w<<endl;
        if (w < x) ans = false;
        ans? cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
}