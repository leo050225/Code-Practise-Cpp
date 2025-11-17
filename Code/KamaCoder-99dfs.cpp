#include <iostream>
using namespace std;
#include <vector>

int dir[4][2] = {0,1,0,-1,1,0,-1,0};

void dfs(vector<vector<int>> &graph, vector<vector<bool>> &visited, int x, int y)
{
    if(visited[x][y] || graph[x][y] == 0)return;

    visited[x][y] = true;

    for(int i = 0; i<4; i++)
    {
        int nextX = x + dir[i][0];
        int nextY = y + dir[i][1];

        if(nextX >= graph.size() || nextX < 0 || nextY >= graph[0].size() || nextY < 0) continue;

        dfs(graph, visited, nextX, nextY);
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> graph(n, vector<int>(m,0));
    vector<vector<bool>> visited(n, vector<bool>(m,false));
    int result = 0;

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin >> graph[i][j];
        }
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(graph[i][j] == 1 && !visited[i][j])
            {
                result++;
                dfs(graph, visited, i, j);
            }
        }
    }

    cout << result << endl;
}
