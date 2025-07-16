#include<iostream>
#include<vector>
#include<math.h>

// Cant solve it on my own, I was thinking about Brute Force with 3 for loops but that would give TLE, (10^3)^3
// Then I thought of prefix sum but that would also not work I think
// Cant think of anything sorting, 1 0 2 4 3 | 4 5 1 0 2 => sort => 0 1 2 3 4 | 0 1 2 4 5 => sum would be wrong for any segment now because relative ordering is disturbed

// Brute force with some optemisation might work

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int n; cin>>n;
        vector<int> b(n, -1);
        for (auto &it : b) cin>>it;
        vector<int> a;
        for (int bi : b){
            a.push_back(pow(2, bi));
        }
        vector<long long> prefix;
        int sum = 0;
        for (long long x : a){
            sum+=x;
            prefix.push_back(sum);
        }
        for (int i = 0; i < n; i++){
            
        }
    }
}