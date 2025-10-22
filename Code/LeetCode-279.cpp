#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        for(int i = 1; i<=sqrt(n); i++)
        {
            for(int j = (i * i); j<=n; j++)
            {
                dp[j] = min(dp[j] , dp[j - (i * i)] + 1);
            }
        }

        return dp[n];
    }
};

int main()
{

}
