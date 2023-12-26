#include <iostream>
#include <unordered_map>

using namespace std;

int longestPalindrome(string);

int main()
{
    string s = "Abbbbb";

    int length = longestPalindrome(s);

    cout << "The longest palindrome is of length : "<< length << endl;
}

int longestPalindrome(string s)
{
    unordered_map<char, int> charCount;

    for(auto ch : s)
    {
        charCount[ch]++;
    }

    int palindromeLength = 0;
    bool hasOddFrequency = false;

    for(auto pair : charCount)
    {
        if(pair.second % 2 == 0)
        {
            palindromeLength += pair.second;     
        }
        else
        {
            palindromeLength += pair.second - 1;
            hasOddFrequency = true;
        }
    }

    if (hasOddFrequency)
    {
        palindromeLength++;
    }

    return palindromeLength;
}