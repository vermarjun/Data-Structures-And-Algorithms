#include<iostream>
#include<string>

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n; char c; string s;
        cin>>n>>c>>s;
        int green = 0;
        for (char c : s) {
            green++;
            if (c == 'g') break;
        }
        int ans = 0;
        for (int i = n - 1; i >= 0; i--){
            if (s[i] == 'g') green = 1;
            else {
                if (s[i] == c){
                    ans = max(ans, green);
                }
                green++;
            }
        }
        cout<<ans<<endl;
    }
}