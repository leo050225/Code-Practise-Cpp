#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size() == 1)return nums[0];

        vector<int> dp(nums.size(), 0);
        
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for(int i = 2; i<dp.size(); i++)
        {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
        }

        return dp[dp.size() - 1];
    }
};

int main()
{
    
}
