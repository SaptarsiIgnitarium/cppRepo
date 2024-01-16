#include <iostream>
using namespace std;

int uniquePaths(int i, int j) 
{
    if (i == 1 && j == 1)  //base case only one way to move from the border cells top or left
    {
        return 1;
    }
    if (i<=0 || j<=0) //for checking out of bounds
    {
        return 0;
    }

    int up = uniquePaths(i - 1, j); 
    int left = uniquePaths(i, j - 1); 
    
    return up + left; 
}

int main() {
    int m = 3;
    int n = 3;

    int result = uniquePaths(m, n);
    cout << "Number of unique paths: " << result << endl;

    return 0;
}
