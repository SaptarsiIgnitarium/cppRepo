#include <iostream>
#include <vector>

using namespace std;

vector<int> spiralOrder(vector<vector<int>>& );

int main()
{
    vector<vector<int>> matrix = {{1,2,3},
                                  {4,5,6},
                                  {7,8,9}};

    vector<int> result = spiralOrder(matrix);

    cout << "Spiral order output is : ";
    for (auto var : result)
    {
        cout << var << " ";
    }
    cout << endl;

    return 0;
}

vector<int> spiralOrder(vector<vector<int>>& matrix)
{
    vector<int> ans;

    if(matrix.empty() || matrix[0].empty())
    {
        return ans;      //base condition
    }

    int left = 0;
    int right = matrix[0].size() - 1;
    int top = 0;
    int bottom = matrix.size() - 1;

    while (left <= right && top <= bottom)
    {
        for(int j = left; j <= right; j++)
        {
            ans.push_back(matrix[top][j]);
        }
        top++;

        for(int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if(top <= bottom && left <= right)   //check if top has not crossed bot 
        {
            for(int j = right; j>= left; j--)
            {
                ans.push_back(matrix[bottom][j]);
            }
            bottom--;
        }

        if(left <= right && top <= bottom)  //check if left has not crossed right to avoid duplicate
        {
            for(int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }
    return ans;
}
