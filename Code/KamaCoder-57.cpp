#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

int main()
{
    int n, m;//總共階數 最多幾步
    cin>>n>>m;
    vector<int> dp(n + 1,0);
    dp[0] = 1;

    for(int i = 1; i<=n; i++)
    {
        for(int j = 1; j<=m; j++)
        {
            if(i - j >= 0)
            dp[i] += dp[i - j];
        }
    }
    cout<< dp[n] << endl;
}
