#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n, r, b; cin>>n>>r>>b;
        int all = floor(double(r) / double(b + 1.00));
        int extra = r % (b+1);
        string ans = "";
        for (int i = 0; i < extra; i++){
            ans = ans + string(all, 'R') + "R";
            r = r - (all+1);
            if (b > 0){
                ans.push_back('B');
                b--;
            }
        }   
        while (r > 0){
            ans = ans + string(all, 'R');
            r = r - all;
            if (b > 0){
                ans.push_back('B');
                b--;
            }
        }
        cout<<ans<<endl;
    }
}