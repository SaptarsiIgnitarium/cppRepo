#include <iostream>
#include <vector>
using namespace std;

int search(vector<int>& nums, int target);

int main()
{
    vector<int> nums = {1,2,3,4,5,6};
    int target = 9;

    int index = search(nums, target);

    if (index == -1)
    {
        cout << "Target not found in the array" << endl;
    }
    else
    {
        cout << "Target found in the index : "<< index << endl;
    }

    return 0;
}
int search(vector<int>& nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right)
    {
        int mid = left + (right - left)/2;

        if(nums[mid] == target)
        {
            return mid;  //target found
        }
        else if (nums[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
        
    }

    return -1;  //target not found in the array
}