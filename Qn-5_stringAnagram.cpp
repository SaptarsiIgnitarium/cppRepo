#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isAnagram(string, string);

int main()
{
    string s1 = "abcd";
    string t1 = "dcbe";

    if(isAnagram(s1,t1))
    {
        cout << "t is an anagram of s" << endl;
    }
    else{
        cout << "t is not an anagram of s" << endl;
    }
}

bool isAnagram(string s, string t)
{
    //check if the length of strings are same
    if(s.length() != t.length())
    {
        return false;
    }

    //sort the strings
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());

    //comparing the strings
    for(int i = 0; i <= s.length()-1; i++)
    {
        if(s[i] != t[i])
        {
            return false;
        }
    }

    return true;
}