#include <iostream>
using namespace std;

int noOfWays(int);

int main()
{
    int numberOfsteps;

    cout << "Enter the number of steps" << endl;
    cin >> numberOfsteps;

    cout << "Number of ways to climb are : " << noOfWays(numberOfsteps);

    return 0;
}

int noOfWays(int n)
{
    if (n == 1)
        return 1;

    int arr[n+1];
    arr[1] = 1;     //to climb 1 step
    arr[2] = 2;     //to climb 2 steps

    int i;

    for(i = 3; i <= n; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }

    return arr[n];

}