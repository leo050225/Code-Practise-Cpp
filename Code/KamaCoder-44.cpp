#include <iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include <climits>

int main()
{
    int n ,m;
    cin>>n>>m;

    int sum = 0;//記得初始化

    int minNum = INT_MAX;

    int count = 0;

    vector<vector<int>>v(n,vector<int>(m));
    
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            cin>>v[i][j];
            sum+=v[i][j];
        }
    }

    //行
    for(int i = 0; i<n; i++)
    {
        for(int j = 0; j<m; j++)
        {
            count+=v[i][j];
        }
        minNum = min(minNum , abs(sum - count - count));
    }

    count = 0;

    //列
    for(int j = 0; j<m; j++)
    {
        for(int i = 0; i<n; i++)
        {
            count+=v[i][j];
        }
        minNum = min(minNum,abs(sum - count - count));
    }

    cout<<minNum<<endl;

    return 0;
}
