#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> sortColors(vector<int>);
void printArray(vector<int>);

int main()
{
    vector<int> nums = {1,2,0,1,2,0,1};

    cout << "Before sorting array is :";
    printArray(nums);

    vector<int> result = sortColors(nums);
    cout << "Sorted array is : ";
    printArray(result);

    return 0;

}

vector<int> sortColors(vector<int> nums)
{
    int low = 0;   //colour 0
    int mid = 0;   //colour 1
    int high = nums.size() - 1;  //colour 2

    while(mid <= high)
    {
        if(nums[mid] == 0)
        {
            swap(nums[mid], nums[low]);
            mid++;
            low++;
        }
        else if(nums[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
    return nums;
}

void printArray(vector<int> arr)
{
    for(auto data : arr)
    {
        cout << data << " ";
    }
    cout << endl;
}

