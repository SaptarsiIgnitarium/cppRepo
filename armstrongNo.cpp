#include <iostream>
using namespace std;

int main()
{
    int arm,temp,temp2,sum = 0;

    cout << "Give the input number :";
    cin >> arm;

    temp2 = arm;

    while (arm > 0)
    {
        temp = (arm % 10);
        sum = sum + (temp*temp*temp);
        arm = arm/10;
    }

    if (sum == temp2)
    {
        cout << "\nThe number is Armstrong";
    }
    else 
        cout << "\nThe number is not Armstrong"; 
}