#include<iostream>
using namespace std;
#include<vector>
#include<queue>
#include<unordered_map>

int main()
{
    
    int n, m;//n個文件 m條關係 
    int s, t;
    cin>>n>>m;

    vector<int> indegree(n, 0);
    unordered_map<int,vector<int>> umap;

    while(m--)
    {
        cin>>s>>t;
        indegree[t]++;
        umap[s].push_back(t);
    }

    queue<int> que;
    vector<int> result;

    for(int i = 0; i<n; i++)
    {
        if(indegree[i] == 0)
            que.push(i);
    }

    while(!que.empty())
    {
        int cur = que.front();
        que.pop();
            
        result.push_back(cur);

        vector<int> file = umap[cur];

        if(file.size())
        {
            for(int n : file)
            {
                indegree[n]--;
                    
                if(indegree[n] == 0)
                    que.push(n);
            }
        }
    }

    if(result.size() == n)
    {
        for(int i = 0; i<result.size() - 1; i++)
        {
            cout<<result[i]<<" ";
        }
        cout<<result[result.size() - 1];
    }
    else
    {
        cout<<-1;
    }
    cout<<endl;
}
