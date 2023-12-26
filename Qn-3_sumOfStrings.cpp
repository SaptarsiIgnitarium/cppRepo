#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string addString(string a,string b);

int main()
{
    string a = "1101" , b = "100";
    cout << addString(a,b);

    return 0;
}

string addString(string a,string b)
{
    if(a.length() > b.length())
    {
        return addString(b,a);
    }

    int lengthdiff = b.length() - a.length();

    string padding = "";

    for (int i = 0; i < lengthdiff; i++)
    {
        padding.push_back('0');
    }
    a = padding + a;

    string result;
    char carry = '0';

    for (int i = b.length() - 1; i>=0; i--)
    {
        if(a[i] == '1' && b[i] == '1')
        {
            if(carry == '1')
            {
                result.push_back('1');
            }
            else
            {
                result.push_back('0');
            }
            carry = '1';
        }

        else if(a[i] == '0' && b[i] == '0')
        {
            if(carry == '1')
            {
                result.push_back('1');
                carry = '0';
            }
            else
            {
                result.push_back('0');
            }
        }

        else
        {
            if(carry == '1')
            {
                result.push_back('0');
            }
            else
            {
                result.push_back('1');
            }
        }        
    }

    if (carry == '1')
        result.push_back('1');

    reverse(result.begin(), result.end());

    return result;
}