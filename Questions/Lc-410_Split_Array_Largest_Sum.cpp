#include <iostream>
#include <vector>
#include <string.h>

using namespace std;
// using binary search here
// This is very similar to standard book allocation problem

int check(vector<int> nums, int sumCheck, int k) //Checker function
{
    int arrays = 0; // sumCheck se kitne arrays banenge hai ye
    int i = 0; //index
    int size = nums.size();
    while (i < size)
    {
        bool zeroPresentinSubArray = false; //To check agar mere sub array me kahin 0 hai kya, because sum = 0 2 tarike se aa sakta hai:
        // 1) while loop execute hi na ho
        // 2) sub array ka element hi 0 ho which is a valid case to agar element zero hua to isko true kardunga mai
        int sum = 0;
        while (i < size && sum <= sumCheck)
        {
            if (nums[i] == 0) zeroPresentinSubArray = true;
            if (sum + nums[i] > sumCheck) break; // checking before hand ki add karne se currentSum bahar nahi chala jaye sumCheck ke 
            sum += nums[i];
            i++;
        }
        if (sum == 0 && !zeroPresentinSubArray) return -1;
        arrays++;
    }
    return arrays;
}
int splitArray(vector<int> &nums, int k)
{
    int totalSum = 0;
    for (int x : nums) totalSum += x;
    int s = 0;
    int e = totalSum;
    int ans = 0;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        int subArrays = check(nums, mid, k);
        if (subArrays >= 0 && subArrays <= k)
        {
            ans = mid; //Ho sakta hai ye hi answer ho so save it
            e = mid - 1; // Keep checking for a smaller solution
        }
        else
        {
            s = mid + 1; // is sum ke sath zada arrays banenege try a larger sum jisse maybe kam arrays banein
        }
    }
    return ans;
}

int main()
{
    vector<int> nums = {7,2,5,10,8};
    int k = 2;
    cout<<splitArray(nums, k);
}