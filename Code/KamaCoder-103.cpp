#include<iostream>
using namespace std;
#include<vector>

int dir[4][2] = {1,0,-1,0,0,1,0,-1};

void dfs(vector<vector<int>> &grid,vector<vector<bool>> &v, int x, int y)
{
    if(v[x][y])return;
    
    v[x][y] = true;

    for(int i = 0; i<4; i++)
    {
        int nextX = x + dir[i][0];
        int nextY = y + dir[i][1];

        if(nextX<0 || nextX>=grid.size() || nextY<0 || nextY>=grid[0].size())continue;
        
        if(grid[x][y] <= grid[nextX][nextY])
            dfs(grid, v, nextX, nextY);
    }
}

int main()
{
    int n, m;
    cin>>n>>m;

    vector<vector<int>> grid(n,vector<int>(m,0));
    vector<vector<bool>> v1(n, vector<bool>(m, false));
    vector<vector<bool>> v2(n, vector<bool>(m, false));

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin>>grid[i][j];
        }
    }

    for(int i = 0; i<n; i++)
    {
        dfs(grid, v1, i, 0);//左
        dfs(grid, v2, i, m - 1);//右
    }

    for(int i = 0; i<m; i++)
    {
        dfs(grid, v1, 0, i);//上
        dfs(grid, v2, n - 1, i);//下
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(v1[i][j] && v2[i][j])
                cout<<i<<" "<<j<<endl;            
        }
    }
}
