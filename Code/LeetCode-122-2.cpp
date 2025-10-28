#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(2,vector<int>(2,0));

        dp[0][0] = -prices[0];
        
        int len = prices.size();

        for(int i = 1; i<len; i++)
        {
            dp[i % 2][0] = max(dp[(i - 1) % 2][0], dp[(i - 1) % 2][1] - prices[i]);//當天持有
            dp[i % 2][1] = max(dp[(i - 1) % 2][1], dp[(i - 1) % 2][0] + prices[i]);//當天賣出
        }

        return dp[(len - 1) % 2][1];
    }
};

int main()
{

}
