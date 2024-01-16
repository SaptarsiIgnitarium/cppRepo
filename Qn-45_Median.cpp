#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

float findMedian(vector<int>& arr)
{
    int n = arr.size();

    if(n%2 == 0)
    {
        return (arr[(n/2) - 1] + arr[n/2]) / 2.0;
    }
    else
    {
        return arr[n/2];
    }
}

vector<vector<int>> matrixMultiplication(vector<vector<int>>& matrix1,
        vector<vector<int>>& matrix2)
{
    int rows1 = matrix1.size();
    int cols1 = matrix1[0].size();
    int rows2 = matrix2.size();
    int cols2 = matrix2[0].size();

    if(cols1 != rows2)
    {
        cout << "Matrixes cannot be multiplied" << endl;
        return {};
    }

    vector<vector<int>> result(rows1 , vector<int>(cols2, 0));

    for(int i=0; i<rows1; i++)
    {
        for(int j=0; j<cols2; j++)
        {
            result[i][j] = 0;
            for(int k=0; k<cols1; k++)
            {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

void displayMatrix(vector<vector<int>>& matrix)
{
    for(auto row : matrix)
    {
        for(auto element : row)
        {
            cout << element << " ";
        }
        cout << endl;

    }
    cout << endl;
}

bool isRepeating(vector<int>& myArray)
{
    set<int> myset;
    for(auto it : myArray)
    {
        if(myset.find(it) != myset.end())
        {
            return true;
        }
        myset.insert(it);
    }
    return false;
}

int main()
{
    vector<int> arr = {2,3,4,5};

    float median = findMedian(arr);
    cout << "The median is : " << median << endl;

    vector<vector<int>> matrix1 = {{1,2,3}, {4,5,6}};
    vector<vector<int>> matrix2 = {{7,8}, {9,10}, {11,12}};

    vector<vector<int>> result = matrixMultiplication(matrix1, matrix2);

    cout << "Matrix1 : ";
    displayMatrix(matrix1); 

    cout << "Matrix2 : ";
    displayMatrix(matrix2);

    cout << "multiplid matrix : ";
    displayMatrix(result);

    vector<int> myArray = {1,2,3,4,5,6,7,8};
    if(isRepeating(myArray))
    {
        cout << "There are repetitions in the array" << endl;
    }
    else
    {
        cout << "There are no repetitions in the array" << endl;
    }

    return 0;  
}
