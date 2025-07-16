#include<iostream>

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        long long a, b; cin>>a>>b;
        int ops = 0;
        while (a > b){
            ops++;
            if (a % 8 == 0 && a / 8 >= b){
                a = a/8;
            } else if (a % 4 == 0 && a / 4 >= b) {
                a = a/4;
            } else if (a % 2 == 0 && a / 2 >= b){
                a = a/2;
            } else {
                ops = -1;
                break;
            }
        }
        while (a < b){
            ops++;
            if (a <= LONG_LONG_MAX/8 &&  a * 8 <= b){
                a = a*8;
            } else if (a <= LONG_LONG_MAX/4 && a * 4 <= b) {
                a = a*4;
            } else if (a <= LONG_LONG_MAX/2 && a * 2 <= b){
                a = a*2;
            } else {
                ops = -1;
                break;
            }
        }
        cout<<ops<<endl;
    }
}