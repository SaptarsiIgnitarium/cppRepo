#include <iostream>
using namespace std;

void oddEven(int);

int main()
{
    int num = 0;

    cout << "Give the input number";
    cin >> num;

    oddEven(num);

    return 0;
}

void oddEven(int no)
{
    if (no % 2 == 0)
    {
        cout << "\nThe given number is Even";
    }
    else 
        cout << "\nThe given number is odd";
    
}