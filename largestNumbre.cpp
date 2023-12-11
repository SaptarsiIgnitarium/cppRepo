#include <iostream>
using namespace std;

int main()
{
    int num1,num2,num3;

    cout << "\nGive the value of 1st number :";
    cin >> num1;

    cout << "\nGive the value of 2nd number :";
    cin >> num2;

    cout << "\nGive the value of 3rd number :";
    cin >> num3;

    if (num1>num2 && num1>num3)
    {
        cout << "Largest number is : " << num1;
    }
    else if (num2>num1 && num2>num3)
    {
        cout << "Largest number is : " << num2;
    }
    else
        cout << "Largest number is : " << num3;
    
}