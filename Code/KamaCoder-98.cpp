#include <iostream>
using namespace std;
#include <vector>
#include <algorithm>

vector<vector<int>> result;
vector<int> path;

void dfs(vector<vector<int>> &graph, int x, int n)
{
    if(x == n)
    {
        result.push_back(path);
        return;
    }

    for(int i = 1; i<=n; i++)
    {
        if(graph[x][i] == 1)
        {
            path.push_back(i);
            dfs(graph, i, n);
            path.pop_back();
        }
    }

    return;
}

int main()
{
    int m, n = 0;
    int s, t = 0;
    cin >> n >> m;
    
    vector<vector<int>> graph(n + 1, vector<int>(n + 1, 0));
    
    while(m--)
    {
        cin>>s>>t;
        graph[s][t] = 1;
    }
    path.push_back(1);
    dfs(graph, 1, n);
    path.pop_back();

    if(result.size() == 0)cout<<-1<<endl;

    for(vector<int> v : result)
    {
        for(int i = 0; i<v.size() - 1; i++)
        {
            cout<<v[i];
            cout<<" ";
        }
        cout<<v[v.size() - 1]<<endl;
    }
}

