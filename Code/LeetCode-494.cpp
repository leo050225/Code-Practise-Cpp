#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int i : nums)
        {
            sum += i;
        }
        
        if(abs(target) > sum)return 0;

        if((sum + target) % 2 == 1)return 0;

        int index = (sum + target) / 2;

        vector<int> dp(index + 1, 0);
        dp[0] = 1;

        for(int i = 0; i<nums.size(); i++)
        {
            for(int j = index; j>=nums[i]; j--)
            {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[index];
    }
};

int main()
{

}
