#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int rottenOranges(vector<vector<int>>& grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int vis[n][m];

    queue<pair<pair<int,int>, int>> q;  //{{r,c},t}

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid[i][j] == 2)
            {
                q.push({{i,j},0});
                vis[i][j] = 2;
            }
            else
                vis[i][j] = 0;
        }
    }

    int time = 0;
    int deltarow[] = {-1,0,1,0};
    int deltacol[] = {0,1,0,-1};

    while(!q.empty())
    {
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;
        q.pop();

        time = max(time, t);

        for (int i=0; i<4; i++)
        {
            int nrow = r + deltarow[i];
            int ncol = c + deltacol[i];

            if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m 
            && grid[nrow][ncol] == 1 && vis[nrow][ncol] != 2)
            {
                vis[nrow][ncol] = 2;
                q.push({{nrow,ncol}, t+1});
            }
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(vis[i][j] != 2 && grid[i][j] == 1)
                return -1;
        }
    }

    return time;
}

int main()
{
    vector<vector<int>> grid = {
        {2,1,1},
        {1,1,0},
        {0,0,1}
    };

    int result = rottenOranges(grid);

    cout << result <<" Minutes elapsed for all to be rotten" << endl;

    return 0;
}