#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class islands
{
private:
    void bfs(int row, int col, vector<vector<int>>& vis, vector<vector<char>>& grid)
    {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int,int>> q;
        q.push({row,col});

        while(!q.empty())
        {
            int trow = q.front().first;
            int tcol = q.front().second;
            q.pop();

            //neighbour traversal
            for(int delrow = -1; delrow <= 1; delrow++)
            {
                for(int delcol = -1; delcol <= 1; delcol++)
                {
                    int nrow = delrow + trow;
                    int ncol = delcol + tcol;

                    if(nrow >=0 && nrow < n && ncol >= 0 && ncol < m && grid[nrow][ncol] == '1' && !vis[nrow][ncol])
                    {
                        vis[nrow][ncol] = 1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
    }

public:
    int numofIslands(vector<vector<char>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n, vector<int>(m,0));
        int cnt = 0;

        for(int row = 0; row <n; row++)
        {
            for(int col = 0; col <m; col++)
            {
                if(!vis[row][col] && grid[row][col] == '1')
                {
                    cnt++;
                    bfs(row,col,vis,grid);
                }
            }
        }
        return cnt;
    }
};

int main()
{
    vector<vector<char>> grid = {
        {'0','1','0','0'},
        {'0','1','1','0'},
        {'0','0','0','0'},
        {'1','0','1','0'}
    };
    
    islands ob;
    int result = ob.numofIslands(grid);

    cout << "The no of islands are " << result << endl;

    return 0;
}