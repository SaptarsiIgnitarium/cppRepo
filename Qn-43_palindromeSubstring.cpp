#include <iostream>
#include <string>

using namespace std;

void longestPalindromicSubstring(string );

int main()
{
    string str = "coffee";

    longestPalindromicSubstring(str);
    return 0;
}

void longestPalindromicSubstring(string s)
{
    int len = s.length();
    int start = 0, end = 1;
    int low, high;

    for (int i = 0; i<len; i++)
    {
        //for even length palindrome
        low = i - 1;
        high = i;

        while(low >= 0 && high < len && s[low] == s[high])
        {
            if((high - low + 1) > end)
            {
                start = low;
                end = high - low + 1;
            }
            low--;
            high++;
        }

        low = i-1;
        high = i+1;
        //for odd length palindrome
        while(low >= 0 && high < len && s[low] == s[high])
        {
            if((high - low + 1) > end)
            {
                start = low;
                end = high - low + 1;
            }
            high++;
            low--;
        }
    }

    cout << "Longest Palindromic substring is :";
    for(int i= start; i<=(start+end-1); i++)
    {
        cout << s[i];
    }
}