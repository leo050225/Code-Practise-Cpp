#include <iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> que;
        int freshcount = 0;
        
        for(int i = 0; i<grid.size(); ++i)
        {
            for(int j = 0; j<grid[0].size(); ++j)
            {
                if(grid[i][j] == 2)
                {
                    que.push({i,j});
                }
                else if(grid[i][j] == 1)
                {
                    ++freshcount;
                }
            }
        }

        if(freshcount == 0)
        {
            return 0;
        }

        int minutes = 0;
        int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};

        while(!que.empty() && freshcount > 0)
        {
            minutes++;

            for(int i = 0; i<que.size(); i++)
            {
                pair<int,int> curr = que.front();
                que.pop();

                for(auto& d : dir)
                {
                    int nx = d[0] + curr.first;
                    int ny = d[1] + curr.second;

                    if(nx >= 0 && nx<grid.size() && ny >= 0 && ny < grid[0].size() && grid[nx][ny] == 1)
                    {
                        grid[nx][ny] = 2;
                        freshcount--;
                        que.push({nx,ny});
                    }
                }
            }
        }
        return freshcount == 0 ? minutes : -1;
    }
};

int main()
{
    
}


