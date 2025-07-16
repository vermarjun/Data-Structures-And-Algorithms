#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
    int n = 0;
    cin>>n;
    vector<int> a;
    for (int i = 0; i < n; i++){
        int x; cin>>x;
        a.push_back(x);
    }
    int ans = 0;
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++){
        while(a[i] == a[i+1]){
            i++;
        }
        ans++;
    }
    cout<<ans<<endl;
}