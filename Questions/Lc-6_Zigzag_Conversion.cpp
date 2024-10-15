#include<string.h>
#include<iostream>

using namespace std;

string convert(string s, int k) {
    int size = s.length(), skipUp = 0, skipDown = 0, currRow = 0;
    if (size == k || k == 1) return s;
    string ans = "";
    for (int currRow = 0; currRow<k; currRow++){
        int skipDown = (k-1-currRow + k-1-currRow-1);
        int skipUp = (currRow+currRow-1);
        bool down = true;
        for (int i = currRow; i < size; i++){
            ans.push_back(s[i]);
            if (down){
                if (skipDown+1 == 0){
                    i+=skipUp;
                }
                else {
                    i+=skipDown;
                }
            }
            else {
                if (skipUp+1 == 0){
                    i+=skipDown;
                }
                else {
                    i+=skipUp;
                }
            }
            down=!down;
        }
    }
    return ans;
}
int main(){
    string s =  "PAYPALISHIRING";
    int numRows = 3;
    cout<<convert(s, numRows);
}