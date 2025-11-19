#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int num;

void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y)
{
    visited[x][y] = true;
    num++;

    for(int i = 0; i<4; i++)
    {
        int nextX = x + dir[i][0];
        int nextY = y + dir[i][1];

        if(nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()) continue;

        if(grid[nextX][nextY] == 1 && !visited[nextX][nextY])
        {
            dfs(grid, visited, nextX, nextY);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    
    int result = 0;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin >> grid[i][j];
        }
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(!visited[i][j] && grid[i][j] == 1)
            {
                num = 0;
                dfs(grid, visited, i, j);
                result = max(result, num);
            }
        }
    }
    cout<< result <<endl;
}
