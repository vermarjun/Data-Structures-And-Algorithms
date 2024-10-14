#include<iostream>
#include<vector>

using namespace std;

int jump(vector<int>& nums) {
    // O(n^2) solution
    int size = nums.size();
    int i = size-1;
    int moves = 0;
    while (i>=0){
        if (i == 0) return moves;
        int ans = 0;
        for (int j = i-1; j>=0; j--){
            if (j+nums[j] >= i){
                ans = j;  
            }
        }
        i = ans;
        moves++;
    }
    return moves;
}

int main(){
    
}