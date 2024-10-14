#include<iostream>
#include<vector>

using namespace std;

bool canJump(vector<int>& nums) {
    // This is O(n2) solution without DP, needs optimization and also i should do this with dp as well!
    int size = nums.size();
    int i = size-1;
    if (size == 1) return true;
    while (i>=0){
        if (i == 0 && nums[0]!=0) return true;
        for (int j = i-1; j>=0; j--){
            if (j+nums[j] >= i){
                i = j;
                break;
            }
            if (j == 0) return false;
        }
    }
    return true;
}

int main(){
    vector<int> nums = {2,3,1,1,4};
    cout<<canJump(nums);
}