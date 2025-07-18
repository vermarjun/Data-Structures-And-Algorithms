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
        int x; cin>>x;
        int ans = INT_MAX;
        while (x>0){
            int y = x % 10;
            ans = min(ans, y);
            x = x / 10;
        }
        cout<<ans<<endl;
    }
}