#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<vector<int>> kClosest(vector<vector<int>>& ,int);

int main()
{
    vector<vector<int>> points = {{3,3}, {5,-1}, {-2,4}, {5,7}, {1,0}};
    int k = 2;

    vector<vector<int>> closestPoints = kClosest(points, k);

    cout << "The k closest points are : ";
    for(const auto& point : closestPoints)
    {
        cout << "[" << point[0] << ", " << point[1] << "]";
        cout << endl;
    }

    return 0;
}

vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
{
    priority_queue<pair<int, vector<int>>> maxHeap;

    for(const auto& point : points)
    {
        int distance = point[0]*point[0] + point[1]*point[1];

        maxHeap.push({distance,point});  //or push(make_pair(distance, point))

        if(maxHeap.size() > k)
        {
            maxHeap.pop();  //pops the top element
        }
    }

    vector<vector<int>> result;
    while(!maxHeap.empty())
    {
        //can only access the top element in pq
        result.push_back(maxHeap.top().second);  //puts the points part of pair into the result vector
        maxHeap.pop();
    }

    //reverse(result.begin(), result.end());  //to get sequential answer
    return result;
}
