#include<iostream>
#include<string.h>

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        string a, b; cin>>a>>b;
        int ans = 0;
        for (int i = 0; i < a.length(); i++){
            for (int j = 0; j < b.length(); j++){
                int temp_i = i, temp_j = j, temp_ans = 0;
                while (temp_i < a.length() && temp_j < b.length() && a[temp_i] == b[temp_j]){
                    temp_i++; temp_j++; temp_ans++;
                }
                ans = max(ans, temp_ans);
            }
        }
        cout<<(a.length() - ans) + (b.length() - ans)<<endl;
    }
}