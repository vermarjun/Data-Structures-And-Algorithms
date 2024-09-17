#include <iostream>
#include<string.h>
#include<limits.h>
#include<vector>
#include<algorithm>

using namespace std;

int convertMins(string s)
{
    // HH
    int hrs = stoi(s.substr(0, 2));
    hrs = hrs * 60;
    int mins = stoi(s.substr(3, 4));
    int time = hrs + mins;
    return time;
}
int findMinDifference(vector<string> &timePoints){
    vector<int> mins;
    int ans = INT_MAX;
    for (int i = 0; i < timePoints.size(); i++)
    {
        int time = convertMins(timePoints[i]);
        mins.push_back(time);
    }
    sort(mins.begin(), mins.end());
    for (int i = 0; i < mins.size() - 1; i++)
    {
        ans = min(ans, (mins[i + 1] - mins[i]));
    }
    // reverse wala case
    int EdgeCase = (mins[0] + 1440) - mins[mins.size() - 1];
    ans = min(ans, EdgeCase);
    return ans;
}

int main(){
    vector<string> v = {"23:59","00:00"};
    cout<<findMinDifference(v);
}