#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

int findMaxLength(vector<int>& nums) {
    // Best thing to notice here is, Sliding window se nahi hoga ye question
    // REASON? variable size SW ek time ke baad choti hogi and you don't know 
    // ki us point ke baad bhi number of 1's and 0's equal ho sakte hain
    // Fixed size sliding window ka to sawal hi nahi uthta!
    // ALTERNATIVE?
    // prefix sum?
    unordered_map<int,int> hash;
    int sum = 0;
    hash[0] = -1;
    int ans = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++){
        if (nums[i] == 1){
            sum+=1;
        }
        else {
            sum-=1;
        }
        if (hash.count(sum)){
            ans = max(ans, abs(i - hash[sum]));
        }
        else {
            hash[sum] = i;
        }
    }
    return ans;
}

int main(){
    
}