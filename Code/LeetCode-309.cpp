#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int len = prices.size();

        vector<vector<int>> dp(len, vector<int>(4, 0));

        dp[0][0] = -prices[0];//持股
        dp[0][1] = 0;//沒有股
        dp[0][2] = 0;//賣出
        dp[0][3] = 0;//冷凍

        for(int i = 1; i<len; i++)
        {
            dp[i][0] = max(dp[i - 1][0], max(dp[i - 1][1] - prices[i], dp[i - 1][3] - prices[i]));
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][3]);
            dp[i][2] = dp[i - 1][0] + prices[i];
            dp[i][3] = dp[i - 1][2]; 
        }

        return max(dp[len - 1][1], max(dp[len - 1][2], dp[len - 1][3]));
    }
};

int main()
{
    
}
