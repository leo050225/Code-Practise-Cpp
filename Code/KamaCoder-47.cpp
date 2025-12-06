#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<queue>
#include<climits>

class mycomparison{
public:
    bool operator()(const pair<int,int>& lhs, const pair<int,int>& rhs)
    {
        return lhs.second > rhs.second;
    }
};

struct Edge
{
    int to;
    int val;

    Edge(int t, int w) : to(t), val(w){} 
};

int main()
{
    int n, m, p1, p2, val;
    
    cin>>n>>m;

    vector<list<Edge>> grid(n+1);

    while(m--)
    {
        cin>>p1>>p2>>val;
        grid[p1].push_back(Edge(p2,val));
    }

    vector<int> minDist(n+1, INT_MAX);

    vector<bool> visited(n+1, false);

    priority_queue<pair<int,int>, vector<pair<int,int>>, mycomparison> pq;

    pq.push(pair<int,int>(1,0));

    minDist[1] = 0;

    while(!pq.empty())
    {
        pair<int,int> cur = pq.top();
        pq.pop();

        if(visited[cur.first]) continue;

        visited[cur.first] = true;

        for(Edge edge : grid[cur.first])
        {
            if(!visited[edge.to] && minDist[cur.first] + edge.val < minDist[edge.to])
            {
                minDist[edge.to] = minDist[cur.first] + edge.val;

                pq.push(pair<int,int>(edge.to, minDist[edge.to]));
            }
        }
    }

    if(minDist[n] == INT_MAX)cout<<-1<<endl;
    else  cout<<minDist[n]<<endl;
}

// #include<iostream>
// using namespace std;
// #include<vector>
// #include<climits>

// int main()
// {
//     int n, m, p1, p2, val;

//     cin>>n>>m;

//     vector<vector<int>> grid(n+1, vector<int>(n+1, INT_MAX));

//     while(m--)
//     {
//         cin>>p1>>p2>>val;
//         grid[p1][p2] = val;
//     }

//     vector<int> minDist(n+1, INT_MAX);

//     vector<bool> visited(n+1, false);

//     minDist[1] = 0;

//     for(int i = 1; i<=n; i++)
//     {
//         int minVal = INT_MAX;
//         int cur = 1;

//         for(int j = 1; j<=n; j++)
//         {
//             if(!visited[j] && minDist[j] < minVal)
//             {
//                 minVal = minDist[j];
//                 cur = j;
//             }
//         }

//         visited[cur] = true;

//         for(int v = 1; v<=n; v++)
//         {
//             if(!visited[v] && grid[cur][v] != INT_MAX && minDist[cur] + grid[cur][v] < minDist[v])
//             {
//                 minDist[v] = minDist[cur] + grid[cur][v];
//             }
//         }
//     }

//     if(minDist[n] == INT_MAX)
//         cout<<-1<<endl;
//     else
//         cout<<minDist[n]<<endl;
// }
