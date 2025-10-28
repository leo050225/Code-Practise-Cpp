#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<int>> dp(2, vector<int>(2*k+1, 0));

        for(int i = 1; i<=2*k; i+=2)
        {
            dp[0][i] = -prices[0];
            dp[0][i + 1] = 0;
        }

        int len = prices.size();

        for(int i = 1; i<len; i++)
        {
            dp[i % 2][0] = dp[(i - 1) % 2][0];

            for(int j = 0; j<2*k; j+=2)
            {
                dp[i % 2][j + 1] = max(dp[(i - 1) % 2][j + 1], dp[i % 2][j] - prices[i]);//持有
                dp[i % 2][j + 2] = max(dp[(i - 1) % 2][j + 2], dp[i % 2][j + 1] + prices[i]);//不持有
            }
        }

        return dp[(len - 1) % 2][2*k];
    }
};

int main()
{

}
