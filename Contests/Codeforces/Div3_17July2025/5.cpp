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
        int n; cin>>n;
        vector<int> p(n, -1);
        for (auto &it : p) cin>>it;
        vector<int> s(n, -1);
        for (auto &it : s) cin>>it;
        bool ans = true;
        int index = -1;
        for (int i = 0; i < n; i++){
            if (p[i] == s[i]) index = i;
        }
        if (index == -1) ans = false;
        else {
            for (int i = 0; i < index; i++){
                if (p[i] < s[i]) ans = false;
            }
            for (int i = index; i < n; i++){
                if (p[i] > s[i]) ans = false;
            }
        }
        (ans)? cout<<"YES"<<endl:cout<<"NO"<<endl;
    }
}