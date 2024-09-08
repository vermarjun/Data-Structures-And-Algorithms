#include <iostream>
#include <string.h>
#include <unordered_map>
using namespace std;

string minWindow(string s, string t)
{
    int tlen = t.length();
    int slen = s.length();
    unordered_map<char, int> hash;
    for (char x : t)
    {
        hash[x]--;
    }
    int start = 0;
    bool found = true;
    string ans = "";
    int end = 0;
    while (end < slen)
    {
        if (hash.count(s[end])) hash[s[end]]++;
        found = true;
        for (auto x : hash)
        {
            if (x.second < 0)
            {
                found = false;
                break;
            }
        }
        if (found)
        {
            while (found)
            {
                if (hash.count(s[start]))
                {
                    hash[s[start]]--;
                    if (hash[s[start]] < 0) found = false;
                }
                start++;
            }
            if (ans.length() >= (end - start + 1) || ans.length() == 0)
            {
                // Save it in your ans if new found ans's length is less than ans
                ans = s.substr(start - 1, end - (start - 1) + 1);
            }
            end++;
        }
        else if (!found && ans.length() > 0)
        {
            // FIXED SIZE KI WINDOW KO AGE SLIDE KARNA HAI
            if (hash.count(s[start]))
            {
                hash[s[start]]--;
            }
            start++;
            end++;
        }
        else
        {
            end++;
        }
    }
    return ans;
}

int main()
{
    string s = "ADOBECODEBANC";
    string t = "ABC";
    cout<<minWindow(s, t); //Ans is BANC
}