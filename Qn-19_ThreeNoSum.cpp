#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeSum(vector<int>&);

int main()
{
    vector<int> nums = {-1, -1, 2, 0, 1}; 

    vector<vector<int>> result = threeSum(nums);

    for(const auto& set : result)
    {
        cout << "[";
        for(auto num : set)
        {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}

vector<vector<int>> threeSum(vector<int>& nums)
{
    vector<vector<int>> result;  //vector to store the sets of triplets

    sort(nums.begin(),nums.end());

    for(int i=0; i < nums.size() - 2; i++)
    {
        if (nums[i] == nums[i - 1] && i > 0)  //ignoring when i = 0
        {
            continue;
        }
        
        //using 2 pointer approach
        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right)
        {
            int sum = nums[i] + nums[left] + nums[right];

            if(sum == 0)
            {
                result.push_back({nums[i], nums[left], nums[right]});

                left++;
                right--;
                while(left < right && nums[left] == nums[left - 1]) 
                    left++;
                while(left < right && nums[right] == nums[right + 1]) 
                    right--;
            }
            else if(sum > 0)
            {
                right--;
            }
            else
            {
                left++;
            }
        }
        
    }

    return result;
}