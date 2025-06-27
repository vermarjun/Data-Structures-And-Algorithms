#include<iostream>

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        int a, b, c; cin>>a>>b>>c;
        bool ans = false;
        // case 1
        int d1 = b - a;
        int expected_c = d1 + b;
        if (expected_c % c == 0 && (expected_c / c) > 0) ans = true;
        // case 2
        int d2 = b - c;
        int expected_a = d2 + b;
        if (expected_a % a == 0 && (expected_a / a) > 0) ans = true;
        // case 3
        if (((a+c) % 2 == 0) && ((a+c)/2 % b == 0) && a+c > 0) ans = true;

        ans ? cout<<"Yes"<<endl : cout<<"No"<<endl;
    }
}