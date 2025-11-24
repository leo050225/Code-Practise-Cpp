#include<iostream>
using namespace std;
#include<vector>

int main()
{
    int n, m;
    cin>>n>>m;

    vector<vector<int>> grid(n, vector<int>(m, 0));
    int dir[4][2] = {1,0,-1,0,0,1,0,-1};

    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin>>grid[i][j];
        }
    }

    int result = 0;

    for(int i = 0; i<n ; i++)
    {
        for(int j = 0; j<m; j++)
        {
            if(grid[i][j] == 1)
            {
                for(int k = 0; k<4; k++)
                {
                    int nextI = i + dir[k][0];
                    int nextJ = j + dir[k][1];

                    if(nextI < 0 || nextI >= grid.size() || nextJ < 0 || nextJ >= grid[0].size() || grid[nextI][nextJ] == 0)
                        result++;
                }
            }
            
        }
    }

    cout<<result<<endl;
}
