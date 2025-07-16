#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        vector<int> v(n, -1);
        for (auto &it : v) cin>>it;
        if (n%2 == 0){
            cout<<2<<endl;
            cout<<1<<" "<<n<<endl;
            cout<<1<<" "<<n<<endl;
        } else {
            cout<<4<<endl;
            cout<<1<<" "<<n<<endl;
            cout<<1<<" "<<n-1<<endl;
            cout<<n-1<<" "<<n<<endl;
            cout<<n-1<<" "<<n<<endl;
        }
    }
}