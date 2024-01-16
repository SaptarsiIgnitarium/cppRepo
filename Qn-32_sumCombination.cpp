#include <iostream>
#include <vector>
using namespace std;

void findCombinations(int index, int target, vector<int>& arr, vector<vector<int>>& result, vector<int>& path)
{
    if(target == 0)
    {
        result.push_back(path);
        return;
    }
 
    if(index == arr.size())
        return;


    if(arr[index] <= target)
    {
        path.push_back(arr[index]);
        findCombinations(index, target - arr[index], arr, result, path);
        path.pop_back();
    }

    findCombinations(index+1, target, arr, result, path);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target)
{
    vector<vector<int>> result;
    vector<int> path;

    findCombinations(0, target, candidates, result, path);
    return result;
}

int main()
{
    vector<int> candidates = {2,4,6,8};
    int target = 8;

    vector<vector<int>> comb = combinationSum(candidates, target);

    cout << "The combinations are : ";
    for (auto candidates : comb)
    {
        cout << "[";
        for(auto candidate : candidates)
        {
            cout << candidate << " ";
        }
        cout << "]";
    }
    cout << endl;

    return 0;

}