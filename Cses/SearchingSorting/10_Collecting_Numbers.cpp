#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n; cin>>n;
    vector<int> v;
    for (int i = 0; i < n; i++){
        int x; cin>>x;
        v.push_back(x);
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        bool done = true;
        int base = -1;
        for (int j = i; j < n; j++){
            if (v[j]!=-1){
                done = false;
                base = v[j];
            }
            if (!done){
                v[j] = -1;
            }
            if (j == n-1 && done){
                cout<<
            }
        }
    }
}