#include<iostream>
using namespace std;
#include<vector>
#include<list>

void dfs(vector<list<int>> &graph, vector<bool> &visited, int node)
{
    if(visited[node])return;

    visited[node] = true;

    list<int> keys = graph[node];

    for(int key : keys)
    {
        dfs(graph, visited, key);
    }
}

int main()
{
    int n, k;
    cin>>n>>k;

    vector<list<int>> graph(n + 1, list<int>(0));

    int s,t;

    while (k--)
    {
        cin>>s>>t;
        graph[s].push_back(t);
    }
    

    vector<bool> visited(n+1, false);

    dfs(graph, visited, 1);

    for(int i = 1; i<=n; i++)
    {
        if(!visited[i])
        {
            cout<<-1<<endl;
            return 0;
        }
    }
    cout<<1<<endl;
}
