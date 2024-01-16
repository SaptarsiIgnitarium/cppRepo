#include <iostream>
#include <vector>
using namespace std;

int maxArea(vector<int>&);

int main()
{
    vector<int> height = {1,8,6,2,5,4,8,3,7};

    int result = maxArea(height);
    cout << "Maximum amount of water that can be held : "<< result <<endl;

}

int maxArea(vector<int>& height)
{
    if(height.empty() == true || height.size() < 2)
    {
        return 0;
    }

    int maxWater = 0;
    int left = 0;
    int right = height.size() - 1;

    while( left < right )
    {
        int shortestHeight = min(height[left], height[right]);
        maxWater = max(maxWater, shortestHeight*((right - left)));

        if (height[left] < height[right])
        {
            left++;
        }
        else{
            right--;
        }
        
    }
    return maxWater;
}