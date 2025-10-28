#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2,vector<int>(5,0));

        dp[0][0] = 0;//不操作
        dp[0][1] = -prices[0];//第一次持有
        dp[0][2] = 0;//第一次賣出
        dp[0][3] = -prices[0];//第二次持有
        dp[0][4] = 0;//第二次賣出

        int len = prices.size();

        for(int i = 1; i < len; i++)
        {
            dp[i % 2][0] = dp[(i - 1) % 2][0];
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], -prices[i]);
            dp[i % 2][2] = max(dp[(i - 1) % 2][2], dp[i % 2][1] + prices[i]);
            dp[i % 2][3] = max(dp[(i - 1) % 2][3], dp[i % 2][2] - prices[i]);
            dp[i % 2][4] = max(dp[(i - 1) % 2][4], dp[i % 2][3] + prices[i]);
        }

        return dp[(len - 1) % 2][4];
    }
};

int main()
{

}
