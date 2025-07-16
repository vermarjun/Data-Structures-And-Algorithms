#include<iostream>
#include<math.h>

using namespace std;

int main(){
    long long x; cin>>x;
    if ((x & x-1) == 0){
        cout<<1<<endl;
    } else {
        int temp = x;
        int k = 0;
        while (temp > 0){
            k++;
            temp = temp >> 1;
        }
        cout<<k-1<<endl;
    }
}