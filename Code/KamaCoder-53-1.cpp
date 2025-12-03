#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

int n = 10001;
vector<int> father(n, 0);

struct Edge
{
    int l, r, val;
};

void init()
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



int main()
{
    int v,e;
    int x, y, k;
    int result = 0;

    cin>>v>>e;
    vector<Edge> edges;

    while (e--)
    {
        cin>>x>>y>>k;
        edges.push_back({x, y, k});
    }

    sort(edges.begin(), edges.end(), [](const Edge &a, const Edge &b){
        return a.val < b.val;
    });

    init();

    for(Edge e : edges)
    {
        int n1 = find(e.l);
        int n2 = find(e.r);

        if(n1 != n2)
        {
            result += e.val;
            join(e.l,e.r);
        }
    }

    cout<<result<<endl;
    return 0;
}
