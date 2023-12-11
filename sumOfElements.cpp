#include <iostream>
using namespace std;

int main()
{
    int array[10];
    int arraysize,i,sum = 0;

    cout << "Give the array size : ";
    cin >> arraysize;

    cout << "\nGive the array elements : ";
    for (i = 0; i < arraysize; i++)
    {
        cin >> array[i];
    }
    
    for (i = 0; i < arraysize; i++)
    {
        sum = sum + array[i];
    }

    cout << "The sum of the array is : "<< sum;

    return 0;
}