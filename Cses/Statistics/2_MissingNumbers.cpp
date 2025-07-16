#include<iostream>

using namespace std;

int main(){
    int n; cin>>n;
    long long sum = 0;
    for (int i = 0; i < n-1; i++){
        int x; cin>>x;
        sum+=x;
    }
    long long correctSum = (n*(n-1))/2;
    long long ans = correctSum - sum;
    cout<<correctSum<<" "<<ans;
    cout<<ans<<endl; 
}