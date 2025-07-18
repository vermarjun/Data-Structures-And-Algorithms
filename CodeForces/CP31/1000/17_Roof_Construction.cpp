#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        int value = 0;
        for (int i = n-1; i >= 0; i--){
            cout<<i<<" ";
            if ((i & (i-1)) == 0){
                value = i;
                break;
            }
        }
        for (int i = 0; i < value; i++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}