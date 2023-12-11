#include <iostream>
#include <string>
using namespace std;

int main()
{
    string first,second;

    cout << "Give the 1st input string : ";
    cin >> first;

    cout << "Give the 2hd input string : ";
    cin >> second;

    if (first.length() == second.length())
    {
        cout << "\nThe given strings are equal in length";
    }
    else 
        cout << "\nThe given strings are not equal in length";

    return 0;
}