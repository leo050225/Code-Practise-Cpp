#include<iostream>
using namespace std;
#include<vector>
#include<climits>

int main()
{
    int n, m, p1, p2, val;

    cin>>n>>m;

    vector<vector<int>> grid(n+1, vector<int>(n+1, INT_MAX));

    while(m--)
    {
        cin>>p1>>p2>>val;
        grid[p1][p2] = val;
    }

    vector<int> minDist(n+1, INT_MAX);

    vector<bool> visited(n+1, false);

    minDist[1] = 0;

    for(int i = 1; i<=n; i++)
    {
        int minVal = INT_MAX;
        int cur = 1;

        for(int j = 1; j<=n; j++)
        {
            if(!visited[j] && minDist[j] < minVal)
            {
                minVal = minDist[j];
                cur = j;
            }
        }

        visited[cur] = true;

        for(int v = 1; v<=n; v++)
        {
            if(!visited[v] && grid[cur][v] != INT_MAX && minDist[cur] + grid[cur][v] < minDist[v])
            {
                minDist[v] = minDist[cur] + grid[cur][v];
            }
        }
    }

    if(minDist[n] == INT_MAX)
        cout<<-1<<endl;
    else
        cout<<minDist[n]<<endl;
}
