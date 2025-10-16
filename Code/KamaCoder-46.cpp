#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>


int main()
{
    int m = 0;//種類數量
    int n = 0;//容器大小

    cin >>m;
    cin >>n;

    vector<int> weight(m,0);
    vector<int> value(m,0);

    for(int i = 0; i<m; i++)
    {
        cin >> weight[i];
    }

    for(int i = 0; i<m; i++)
    {
        cin >> value[i];
    }

    vector<vector<int>> dp(m, vector<int>(n + 1,0));

    for(int i = weight[0]; i<=n; i++)//初始化dp
    {
        dp[0][i] = value[0];
    }

    for(int i = 1; i<m; i++)//物品種類號碼
    {
        for(int j = 0; j<=n; j++)//背包重量
        {
            if(j < weight[i])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weight[i]] + value[i]);
        }
    }

    cout<< dp[m - 1][n] <<endl;
}
