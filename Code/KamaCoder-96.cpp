#include<iostream>
using namespace std;
#include<vector>
#include<climits>

int main()
{
    int n, m, s, t, val, start, end, k;

    cin>>n>>m;

    vector<vector<int>> grid;

    while(m--)
    {
        cin>>s>>t>>val;
        grid.push_back({s, t, val});
    }

    cin>>start>>end>>k;

    vector<int> minDist(n+1, INT_MAX);
    vector<int> minDist_copy(n+1);

    minDist[start] = 0;

    for(int i = 1; i<=k+1; i++)
    {
        minDist_copy = minDist;
        
        for(vector<int> &side : grid)
        {
            int from = side[0];
            int to = side[1];
            int price = side[2];

            if(minDist_copy[from] != INT_MAX && minDist[to] > minDist_copy[from] + price)
            {
                minDist[to] = minDist_copy[from] + price;
            }
        }
    }

    if(minDist[end] == INT_MAX)
        cout<<"unreachable"<<endl;
    else
        cout<<minDist[end]<<endl;
}
