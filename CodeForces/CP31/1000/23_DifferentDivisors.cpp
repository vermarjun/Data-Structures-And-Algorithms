#include<iostream>

using namespace std;

int GCD(int a, int b){
    while (b != 0){
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main(){
    int t; cin>>t;
    while (t--){
        int d; cin>>d;
        int first_number = 1 + d;
        int second_number = first_number + d;
        int LCM = (first_number/GCD(first_number,second_number)) * second_number;
        cout<<LCM<<endl;
    }
}