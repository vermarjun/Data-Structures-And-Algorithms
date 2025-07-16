#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

int main(){
    int t; cin>>t;
    while (t--){
        long long n; cin>>n;
        bool changed = false;
        while (!changed){
            changed = true;
            vector<bool> hash(10, false);
            long long digits = n;
            while (digits){
                int digit = digits % 10;
                digits = digits / 10;
                hash[digit] = true;
            }
            for (long long i = 1; i < 10; i++){
                if (hash[i] == true && (n % i) != 0){
                    changed = false;
                    n++;
                    break;
                }
            }
        }
        cout<<n<<endl;
    }
}