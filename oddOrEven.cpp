#include <iostream>
using namespace std;

int main()
{
    int number = 0;

    cout << "Give the input number : ";
    cin >> number;

    if (number % 2 == 0)
    {
        cout << "The given number is even" << endl;
    }
    else 
        cout << "The given number is odd" << endl;
    return 0;     
}