#include <iostream>
#include<vector>
#include<limits.h>
using namespace std;

int longestSubarray(vector<int> &nums)
{
    int maxi = INT_MIN;
    int size = nums.size();
    for (int x : nums)
    {
        maxi = max(x, maxi);
    }
    int ans = INT_MIN;
    for (int i = 0; i < size; i++)
    {
        int x = 0;
        while (i < size && nums[i] == maxi)
        {
            x++;
            i++;
        }
        ans = max(ans, x);
    }
    return ans;
}

int main()
{
    // CONCEPT: The bitwise AND of two different numbers will always be strictly less than the maximum of those two numbers.
    vector<int> nums = {1,2,3,3,2,2};
    cout<<longestSubarray(nums);
}