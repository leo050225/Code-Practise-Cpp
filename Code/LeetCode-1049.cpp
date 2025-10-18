#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;

        for(int i : stones)
        {
            sum += i;
        }

        int target = sum/2;
        
        vector<int> dp(target + 1, 0);

        for(int i = 0; i<stones.size(); i++)
        {
            for(int j = target; j>=stones[i]; j--)
            {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }

        return (sum-dp[target]) - dp[target];
    }
};

int main()
{

}
