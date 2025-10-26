#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(2,vector<int>(2,0));

        dp[0][0] -= prices[0];//第i天 持有股票所得 最多現金
        dp[0][1] = 0;//第i天 不持有股票 所得 最多現金

        for(int i = 1; i<prices.size(); i++)
        {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0] , -prices[i]);
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], prices[i] + dp[(i - 1) % 2][0]);
        }

        return dp[(prices.size() - 1) % 2][1];
    }
};

int main()
{
    
}
