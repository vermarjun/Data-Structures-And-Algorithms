#include <iostream>
#include<vector>
using namespace std;

int specialArray(vector<int> &nums){
    // APPROACH 1: O(log n)
    // sort(nums.begin(), nums.end());
    // int i = 0;
    // int n = nums.size();
    // while (i<=n){
    //     for (int j = 0; j < n; j++){
    //         if (nums[j]>=i){
    //             int x = n - j;
    //             if (x == i) return x;
    //             break;
    //         }
    //     }
    //     i++;
    // }
    // return -1;

    // APPROACH 2: O(N)
    // GAAN FAAD SOLUTION
    // First Iteration me find frequency array
    int size = nums.size();
    vector<int> frequencyArray(1000, 0); // Make an array of size 1000 because of constraints given in question
    for (int num : nums)
    {
        frequencyArray[num]++;
    }
    int grtr = 0;
    for (int i = 999; i >= 0; i--)
    {
        grtr += frequencyArray[i];
        frequencyArray[i] = grtr;
        if (i == grtr)
            return i;
    }
    return -1;
}

int main(){
    vector<int> nums = {3,5};
    cout<<specialArray(nums);
}