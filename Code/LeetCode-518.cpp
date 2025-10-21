#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<uint64_t> dp(amount + 1, 0);

        dp[0] = 1;


        for(int i = 0; i<coins.size(); i++)
        {
            for(int j = coins[i]; j<=amount; j++)
            {
                dp[j] += dp[j - coins[i]];
            }
        }

        return dp[dp.size() - 1];
    }
};

int main()
{

}
