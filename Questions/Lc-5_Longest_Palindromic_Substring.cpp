#include <iostream>

using namespace std;

string longestPalindrome(string s)
{
    int size = s.length();
    int ans = 0;
    string strAns = "";
    for (int i = 0; i < size; i++)
    {
        int pSize = 1;
        string str = "";
        str.push_back(s[i]);
        int j = i + 1;
        while (j < size && s[i] == s[j])
        {
            str.push_back(s[j]);
            pSize++;
            j++;
        }
        int k = i - 1;
        while (k >= 0 && j < size && s[j] == s[k])
        {
            str.insert(str.begin(), s[k]);
            str.push_back(s[j]);
            pSize += 2;
            j++;
            k--;
        }
        if (pSize > ans)
        {
            ans = pSize;
            strAns = str;
        }
    }
    return strAns;
}

int main()
{
    cout<<longestPalindrome("aaaabbbbbbcccccddddddeeeeeeeeeeeeeeeeddddddddccccccccbbbbbbbbbbaaaaaa");
}