#include <iostream>
#include <string>
using namespace std;

int myAtoi(string str);

int main()
{
    string str = "78965";

    int result = myAtoi(str);
    cout << result;

    return 0;
}

int myAtoi(string str)
{
    int result = 0;
    int len = str.length() - 1;

    for (int i = 0; i <= len; i++)
    {
        result = (result * 10) + str[i] - '0';
    }

    return result;
}