#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        double n, k, b, s; cin>>n>>k>>b>>s;
        int avg_element = floor(s / n);
        double max_element = avg_element + ((k-1) - (avg_element % int(k)));
        int mini_beauty = floor(s/max_element) + floor((int(s) % int(max_element))/k);
        int min_element = avg_element - (avg_element % int(k));
        vector<int> ans;
        while (n>=0 && b>=0){

        }
    }
}