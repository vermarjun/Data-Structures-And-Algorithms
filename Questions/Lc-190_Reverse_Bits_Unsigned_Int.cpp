#include<iostream>

using namespace std;

// BEST PROBLEM TO REFRESH BIT MANIPULATION CONCEPTS!

uint32_t reverseBits(uint32_t n) {
    int ans = 0;
    for (int i = 0; i < 32; i++){
        // Right shift you answer!
        ans = ans << 1;
        // One way to Access all the bits of an binary number is to & it with 1. Ex: 111111101 & 1 = 1 || 1111000 & 1 = 0;
        // Then to add it in the answer integer just | the bit with existing answer!
        ans = ans|(n&1);
        // Left shift your number
        n = n >> 1;
    }
    return ans;
}

int main(){
    cout<<reverseBits(32)<<endl;
}