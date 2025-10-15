#include <iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n);
        
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;

        for(int i = 3; i<=n; i++)
        {
            for(int j = 1; j<=i/2; j++)
            {
                dp[i] = max(j * (i - j), max(j * dp[i - j], dp[i]));
            }
        }

        return dp[n];
    }
};

int main()
{
    
}
