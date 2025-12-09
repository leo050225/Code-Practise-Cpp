#include<iostream>
using namespace std;
#include<vector>
#include<list>
#include<queue>
#include<climits>

struct Edge
{
    int to;
    int val;

    Edge(int t, int v) : to(t), val(v){}
};

int main()
{
    int n, m, s, t, val;

    cin>>n>>m;

    vector<list<Edge>> grid(n+1);

    while (m--)
    {
        cin>>s>>t>>val;

        grid[s].push_back(Edge{t, val});
    }

    vector<int> minDist(n+1, INT_MAX);
    vector<bool> isInQueue(n+1);
    queue<int> que;

    minDist[1] = 0;
    que.push(1);
    
    while (!que.empty())
    {
        int node = que.front();
        que.pop();
        isInQueue[node] = false;

        for(Edge edge : grid[node])
        {
            int from = node;
            int to = edge.to;
            int price = edge.val;

            if(minDist[from] + price < minDist[to])
            {
                minDist[to] = minDist[from] + price;

                if(!isInQueue[to])
                {
                    que.push(to);
                    isInQueue[to] = true;
                }
            }
        }
    }
    
    if(minDist[n] == INT_MAX)
        cout<<"unconnected"<<endl;
    else
        cout<<minDist[n]<<endl;
}


// #include<iostream>
// using namespace std;
// #include<vector>
// #include<climits>

// int main()
// {
//     int n , m, s, t, val;

//     cin>>n>>m;

//     vector<vector<int>> grid;

//     while(m--)
//     {
//         cin>>s>>t>>val;
        
//         grid.push_back({s,t,val});
//     }

//     vector<int> minDist(n+1, INT_MAX);

//     minDist[1] = 0;

//     for(int i = 1; i<n; i++)
//     {
//         for(vector<int> &side : grid)
//         {
//             int from = side[0];
//             int to = side[1];
//             int price = side[2];

//             if(minDist[from] != INT_MAX && minDist[from] + price < minDist[to])
//             {
//                 minDist[to] = minDist[from] + price;
//             }
//         }
//     }

//     if(minDist[n] == INT_MAX)
//         cout<<"unconnected"<<endl;
//     else
//         cout<<minDist[n]<<endl;
// }
