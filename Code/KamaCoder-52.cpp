#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>


int main()
{
    int n, bagSize;
    cin>>n>>bagSize;
    
    vector<int> weight(n, 0);
    vector<int> value(n, 0);

    for(int i = 0; i<n; i++)
    {
        cin>>weight[i];
        cin>>value[i];
    }

    vector<int>dp(bagSize + 1);

    for(int i = weight[0]; i<=bagSize; i++)
    {
        dp[i] = dp[i - weight[0]] + value[0];
    }

    for(int i = 0; i<n; i++)
    {
        for(int j = weight[i]; j<=bagSize; j++)
        {
            dp[j] = max(dp[j], dp[j - weight[i]] + value[i]);
        }
    }

    cout<<dp[dp.size() - 1]<<endl;
}
