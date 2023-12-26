#include <iostream>
using namespace std;

bool isBadVersion(int);
int firstBadVersion(int);

int main()
{
    int maxNoofVersion = 10;

    int indexOfFBV = firstBadVersion(maxNoofVersion);

    cout << "The first bad version is at : " << indexOfFBV << endl;

    return 0;
}

bool isBadVersion(int version)
{
   //assuming version 4 and later are bad versions
    if (version >= 4)
    {
        return true;
    }
    else 
    {
        return false;
    }
}

int firstBadVersion(int n)
{
    int left = 1, right = n;

    while (left < right)
    {
        int mid = left + (right - left)/2;
        
        if (isBadVersion(mid))
        {
            right = mid;
        }
        else
        {
            left = mid + 1;
        }
        
    }
    return mid;    
}