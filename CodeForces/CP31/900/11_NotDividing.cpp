#include<iostream>
#include<vector>
#include<math.h>

using namespace std;

// LOGIC:
// ONLY THING TO THINK WAS DIVISOR KO NAHI BADHA NAHI TO FAS JAYEGAG, AND HANDLE 1'S CASE LIKE 1, 1

// IMPLEMENTATION:
// DIVISOR KO BADHANE ME PROBLEM:
// 2, 720 ab yaha 720 is product of 2*3*4*5*6 so kaha tak badhayega 2? kal to dividend bada number bhi ho sakta hai usme fas jayega CASE!!

// 1 ke case me minimum possibility is ki agar last element even hai to isko odd yani 3 daldo, nahi to even yani 2 daldo

// Dono hi 1 ka case nahi aye isliye v[0] == 1 ka case explicitly loop chalu hone se pehle handle karlo!

int main(){
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        vector<int> v(n, -1);
        for (auto &it : v) cin>>it;
        if (v[0] == 1) v[0] = 2;
        for (int i = 1; i < n; i++){
            if (v[i] == 1){
                if (v[i-1] % 2 == 0){
                    v[i] = 3;
                } else {
                    v[i] = 2;
                }
            }
            while (v[i] % v[i-1] == 0){
                v[i]++;
            } 
        }
        for (int x : v) cout<<x<<" ";
        cout<<endl;
    }
}