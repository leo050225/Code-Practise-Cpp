#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        
        if(nums.size() == 1)return 1;

        vector<int> dp(nums.size(), 1);


        int result = 0;

        for(int i = 1; i<nums.size(); i++)
        {
            for(int j = 0; j<i; j++)
            {
                if(nums[i] > nums[j]) dp[i] = max(dp[i], dp[j] + 1);
            }

            if(dp[i] > result) result = dp[i];
        }
        
        return result;
    }
};

int main()
{
    
}
