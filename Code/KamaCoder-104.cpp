#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>
#include<unordered_set>

int dir[4][2] = {1,0,-1,0,0,1,0,-1};
int compSize = 0;


void dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y, int mark)
{
    visited[x][y] = true;
    grid[x][y] = mark;
    compSize++;

    for(int i = 0; i<4; i++)
    {
        int nextX = x + dir[i][0];
        int nextY = y + dir[i][1];
    
        if(nextX<0 || nextX>=grid.size() || nextY<0 || nextY>=grid[0].size())continue;

        if(!visited[nextX][nextY] && grid[nextX][nextY] == 1)
            dfs(grid, visited, nextX, nextY, mark);
    }
}

int main()
{
    int n, m;
    cin>>n>>m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    unordered_map<int,int>gridNum;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin>>grid[i][j];
        }
    }

    int mark = 2;
    bool allGround = true;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if (grid[i][j] == 0) allGround = false;
            if(!visited[i][j] && grid[i][j] == 1)
            {
                compSize = 0;
                dfs(grid, visited, i, j, mark);
                gridNum[mark] = compSize;
                mark++;
            }
        }
    }

    if(allGround)
    {
        cout<<n * m<<endl;
        return 0;
    }

    int result = 0;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(grid[i][j] == 0)
            {
                compSize = 1;
                unordered_set<int> s;
                for(int k = 0; k<4; k++)
                {
                    int nextI = i + dir[k][0];
                    int nextJ = j + dir[k][1];

                    if(nextI<0 || nextI>=grid.size() || nextJ<0 || nextJ>=grid[0].size())continue;

                    if(grid[nextI][nextJ] > 1)
                    {
                        s.insert(grid[nextI][nextJ]);
                    }
                }

                for(int i : s)
                    compSize += gridNum[i];

                result = max(result, compSize);
            }
        }
    }

    cout<<result<<endl;
}
