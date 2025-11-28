#include<iostream>
using namespace std;
#include<vector>

vector<int> father(101, 0);

void init(int n)
{
    for(int i = 1; i<=n; i++)
        father[i] = i;
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
    father[v] = u;//v的跟節點是u
}

bool isSame(int u, int v)
{
    return find(u) == find(v);
}

int main()
{
    int n, m, s, t, begin, end;

    cin>>n>>m;

    init(n);

    while(m--)
    {
        cin>>s>>t;
        join(s,t);
    }

    cin>>begin>>end;

    if(isSame(begin, end))
        cout<<1<<endl;
    else
        cout<<0<<endl;
}
