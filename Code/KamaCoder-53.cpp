#include<iostream>
using namespace std;
#include<vector>
#include <climits>

int main()
{
    int v, e;
    int x, y, k;
    cin>>v>>e;

    vector<vector<int>> grid(v + 1, vector<int>(v + 1, 10001));// 連接的線和權值

    while(e--)
    {
        cin>>x>>y>>k;
        grid[x][y] = k;
        grid[y][x] = k;
    }

    vector<int>minDist(v + 1, 10001);// 離生成樹最小距離
    vector<int>isInTree(v + 1, false);//是否在生成樹

    for(int i = 1; i < v; i++)
    {
        int cur = -1;
        int minVal = INT_MAX;
        
        for(int j = 1; j<=v; j++)
        {
            if(!isInTree[j] && minDist[j] < minVal)
            {
                minVal = minDist[j];
                cur = j;
            }
        }

        isInTree[cur] = true;

        for(int j = 1; j<=v; j++)
        {
            if(!isInTree[j] && grid[cur][j] < minDist[j])
            {
                minDist[j] = grid[cur][j];
            }
        }
    }

    int result = 0;
    for(int i = 2; i<=v; i++)
    {
        result+=minDist[i];
    }

    cout << result <<endl;
}
