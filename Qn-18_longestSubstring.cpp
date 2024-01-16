#include <iostream>
#include <unordered_map>
//#include <cmath>
using namespace std;

int lengthOfLongestSubstring(string);

int main()
{
    string input = "abcaefabc";

    cout << "Length of the longest substring is : " << lengthOfLongestSubstring(input);

    return 0;
}

int lengthOfLongestSubstring(string s)
{
    int len = s.length();

    if(len == 0)
    {
        return 0;
    }

    unordered_map<char, int> charMap;
    int maxLength = 0, start = 0, end = 0;

    for (end = 0; end < len; end++)
    {
        if(charMap.find(s[end]) != charMap.end())
        {
            start = max(start, charMap[s[end]] + 1);
        }

        charMap[s[end]] = end;

        maxLength = max(maxLength, end - start + 1);
    }

    return maxLength;
}