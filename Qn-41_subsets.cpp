#include <iostream>
#include <vector>
#include <set>
using namespace std;

void generateSubsets(int index, vector<int>& nums, vector<vector<int>>& result, vector<int>& subset, set<vector<int>>& uniqueSet) 
{
    if (uniqueSet.find(subset) == uniqueSet.end()) 
    {
            result.push_back(subset);
            uniqueSet.insert(subset); 
    }

    if (index == nums.size()) 
    {   
        return;
    }

    // Include the current element and generate subsets
    subset.push_back(nums[index]);
    generateSubsets(index + 1, nums, result, subset, uniqueSet);

    // Backtrack and exclude the current element to generate more subsets
    subset.pop_back();
    generateSubsets(index + 1, nums, result, subset, uniqueSet);
}

vector<vector<int>> subsets(vector<int>& nums) 
{
    vector<vector<int>> result;
    vector<int> subset;
    set<vector<int>> uniqueSet;

    generateSubsets(0, nums, result, subset, uniqueSet);

    return result;
}

int main() {
    vector<int> candidates = {1, 5, 6};
    vector<vector<int>> comb = subsets(candidates);

    cout << "The subsets are: ";
    for (const auto& subset : comb) {
        cout << "[";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]";
    }
    cout << endl;

    return 0;
}
