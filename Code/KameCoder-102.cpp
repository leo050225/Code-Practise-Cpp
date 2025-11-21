#include<iostream>
using namespace std;
#include<vector>

int dir[4][2] = {1,0,-1,0,0,1,0,-1};

void dfs(vector<vector<int>> &grid, int x, int y)
{
    grid[x][y] = 2;

    for(int i = 0; i<4; i++)
    {
        int nextX = x + dir[i][0];
        int nextY = y + dir[i][1];
    
        if(nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size())continue;

        if(grid[nextX][nextY] == 1)
            dfs(grid, nextX, nextY);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n ,vector<int>(m ,0));
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i<n; i++)
    {
        if(grid[i][0]) dfs(grid, i, 0);
        if(grid[i][m - 1]) dfs(grid, i, m - 1);
    }

    for(int i = 0; i<m; i++)
    {
        if(grid[0][i]) dfs(grid, 0, i);
        if(grid[n - 1][i]) dfs(grid, n - 1, i);
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(grid[i][j] == 1)
                grid[i][j] = 0;
            else if(grid[i][j] == 2)
                grid[i][j] = 1;
        }
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = 0;j<m; j++)
        {
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }
}
