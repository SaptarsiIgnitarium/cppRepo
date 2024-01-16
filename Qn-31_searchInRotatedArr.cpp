#include <iostream>
#include <vector>
using namespace std;

int searchInRotated(vector<int>, int);

int main()
{
    vector<int> nums = {5,6,7,8,0,1,2,3,4};
    int target = 2;

    int result = searchInRotated(nums, target);

    cout << "Index of target is : " << result << endl;
    return 0;
}

int searchInRotated(vector<int> nums, int target)
{
    int left = 0;
    int right = nums.size() - 1;

    while (left < right)
    {
        int mid = left + (right - left)/2;

        if(nums[mid] == target)
        {
            return mid;
        }

        if(nums[left] <= nums[mid])
        {
            if(nums[left] <= target && target < nums[mid])
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        else
        {
            if(nums[right] >= target && target > nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }

        }
    }
    return 0;
}
