#include <iostream>
using namespace std;
#include <vector>
#include <queue>

const int dir[4][2] = {0,1,0,-1,1,0,-1,0};

void bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y)
{
    queue<pair<int,int>> que;
    que.push({x,y});
    visited[x][y] = true;

    while(!que.empty())
    {   
        pair<int,int> cur = que.front();
        que.pop();
        for(int i = 0; i<4; i++)
        {
            int nextX = cur.first + dir[i][0];
            int nextY = cur.second + dir[i][1];

            if(nextX < 0 || nextX >= grid.size() || nextY < 0 || nextY >= grid[0].size()) continue;

            if(grid[nextX][nextY] == 1 && !visited[nextX][nextY])
            {
                que.push({nextX,nextY});
                visited[nextX][nextY] = true;
            }
        }
    }
}


int main()
{
    int n, m;
    cin>>n>>m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    int result = 0;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin>>grid[i][j];
        }
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(grid[i][j] == 1 && !visited[i][j])
            {
                result++;
                bfs(grid, visited, i, j);
            }
        }
    }

    cout<< result <<endl;
}
