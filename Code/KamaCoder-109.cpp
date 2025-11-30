#include<iostream>
using namespace std;
#include<vector>

int n;
vector<int> father(1001, 0); 

void Init()
{
    for(int i = 1; i<=n; i++)
    {
        father[i] = i;
    }
}

int find(int u)
{
    return u == father[u] ? u : father[u] = find(father[u]);
}

void join(int u, int v)
{
    u = find(u);
    v = find(v);
    if(u == v)return;
    father[v] = u;
}

bool isSame(int u, int v)
{
    u = find(u);
    v = find(v);
    return u == v;
}

bool isTree(const vector<vector<int>> &edges, int deletEdge)
{
    Init();
    for(int i = 0; i<n; i++)
    {
        if(i == deletEdge) continue;
        if(isSame(edges[i][0], edges[i][1]))
            return false;
        join(edges[i][0], edges[i][1]);
    }
    return true;
}

void getRemoveEdge(const vector<vector<int>> &edges)
{
    Init();
    for(int i = 0; i<n; i++)
    {
        if(isSame(edges[i][0], edges[i][1]))
        {
            cout<<edges[i][0]<<" "<<edges[i][1]<<endl;
            return;
        }
        else
        {
            join(edges[i][0], edges[i][1]);
        }
    }
}

int main()
{
    int s, t;
    cin>>n;
    
    vector<vector<int>> edges; // 紀錄邊
    vector<int> inDegree(n + 1, 0); // 記錄每個節點入度數量
    
    for(int i = 0; i<n; i++)
    {
        cin>>s>>t;
        inDegree[t]++;
        edges.push_back({s,t});
    }

    vector<int> vec; // 找入度為2的節點所對應的邊 注意要倒序 要優先刪除最後出線的一條邊

    for(int i = n - 1; i>=0; i--)
    {
        if(inDegree[edges[i][1]] == 2)
        {
            vec.push_back(i);
        }
    }
    
    if(vec.size() > 0)
    {
        if(isTree(edges, vec[0]))
        {
            cout<<edges[vec[0]][0]<<" "<<edges[vec[0]][1]<<endl;
        }
        else
        {
            cout<<edges[vec[1]][0]<<" "<<edges[vec[1]][1]<<endl;
        }
        return 0;
    }

    getRemoveEdge(edges);
}
