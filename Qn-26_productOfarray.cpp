#include <iostream>
#include <vector>

using namespace std;

vector<int> productExceptSelf(vector<int>& nums)
{
    int n = nums.size();

    vector<int> left(n, 1);
    vector<int> right(n, 1);
    vector<int> answer(n, 1);

    //calculating products of elements to the left of each element
    for (int i = 1; i < n; i++)
    {
        left[i] = left[i - 1]*nums[i - 1]; 
    }

    //calculating products of elements to the right of each element
    for (int i = (n - 2); i >= 0; i--)
    {
        right[i] = right[i + 1]*nums[i + 1];
    }

    //multiplying the left and right each index
    for (int i=0; i<n; i++)
    {
        answer[i] = left[i] * right[i];
    }

    return answer;
}

int main()
{
    vector<int> nums = {1, 2, 3, 4};
    vector<int> answer = productExceptSelf(nums);

    cout << "The answer array is : ";
    for (auto var : answer)
    {
        cout << var << " ";
    }
    cout << endl;

    return 0;
}