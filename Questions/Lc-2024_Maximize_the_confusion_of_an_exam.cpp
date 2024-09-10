#include <iostream>
#include<limits.h>
#include<string.h>
using namespace std;

int maxConsecutiveAnswers(string ans, int k)
{
    int T = 0, F = 0, i = 0, j = 0;
    int size = ans.length();
    int answer = INT_MIN;
    while (j < size)
    {
        (ans[j] == 'T') ? T++ : F++;
        while (min(T, F) <= k)
        {
            // EXPAND
            answer = max(answer, j - i + 1);
            j++;
            if (j >= size)
            {
                return answer;
            }
            (ans[j] == 'T') ? T++ : F++;
        }
        (ans[i] == 'T') ? T-- : F--;
        i++;
        j++;
    }
    return answer;
}

int main()
{
    string ans = "TTFTTFTT";
    int k= 1; 
    cout<<maxConsecutiveAnswers(ans, k);
}