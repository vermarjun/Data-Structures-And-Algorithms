#include<bits/stdc++.h>

typedef long long ll;

using namespace std;

int main(){
    int t; cin>>t;
    vector<int> v(100000, 0);
    // v[0] = 0, v[1] = 0;
    for (int i = 2; i * i <= 100000; i++){
        if (v[i] == 0){
            int j = 2;
            while (i * j < 100000){
                v[i * j] = 1;
                j++;
            }
        }
    } 
    // for (int i = 0; i < 10; i++) cout<<v[i]<<" ";
    while (t--){
        ll d; cin>>d;
        ll first_number = 1;
        ll second_number = 1 + d;
        while (second_number < 100000 && v[second_number] != 0) second_number++;
        ll third_number = second_number + d;
        while (third_number < 100000 && v[third_number] != 0) third_number++;
        ll fourth_number = (second_number * third_number)/__gcd(second_number, third_number);
        cout<<fourth_number<<endl;
    }
}