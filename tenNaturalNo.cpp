#include <iostream>
using namespace std;

int main()
{
    int sum = 0,i = 1;

    /* for (int i = 1; i <= 10; i++)
    {
        sum = sum + i;
    } */
    
    do
    {
        sum = sum +i;
        i++;
    }
    while (i <= 10);

    cout << "The Sum of first 10 natual numbers is : "<< sum;
    return 0;
}