#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        vector<int> dp(nums1.size() + 1, 0);

        int result = 0;

        for(int i = 1; i<=nums1.size(); i++)
        {
            for(int j = nums2.size(); j>0; j--)
            {
                if(nums1[i - 1] == nums2[j - 1])dp[j] = dp[j - 1] + 1;
                else dp[j] = 0;

                if(dp[j] > result)result = dp[j];
            }
        }

        return result;
    }
};

int main()
{
    
}
