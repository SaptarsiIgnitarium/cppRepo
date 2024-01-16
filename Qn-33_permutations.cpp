#include <iostream>
#include <vector>
using namespace std;

void backtrack(vector<int>& nums, vector<vector<int>>& result, int start) 
{
    if (start == nums.size()) {
        result.push_back(nums); // Add the current permutation to the result
        return;
    }

    for (int i = start; i < nums.size(); ++i) {
        swap(nums[start], nums[i]); // Swap elements to generate permutations
        backtrack(nums, result, start + 1); // Recursive call for the next index
        swap(nums[start], nums[i]); // Backtrack: revert the swap for the next iteration
    }
}

vector<vector<int>> permute(vector<int>& nums) 
{
    vector<vector<int>> result;
    backtrack(nums, result, 0);
    return result;
}

int main() 
{
    vector<int> nums = {1, 2, 3}; // Example input array
    vector<vector<int>> permutations = permute(nums);

    cout << "All possible permutations:" << endl;
    for (const auto& perm : permutations) {
        cout << "[";
        for (int num : perm) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    return 0;
}
