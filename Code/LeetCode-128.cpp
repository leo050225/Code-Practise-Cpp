#include<iostream>
#include<unordered_set>
#include<algorithm>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        if(nums.size() == 0)
            return 0;
        
        sort(nums.begin(), nums.end());

        int sum = 1;
        int maxSum = 1;
        for(int i = 1; i<nums.size(); i++)
        {
            if(nums[i] == nums[i-1])
                continue;

            maxSum = max(maxSum, sum);

            if(abs(nums[i] - nums[i-1]) > 1)
            {
                sum = 1;
                continue;
            }
                sum++;
        }

        maxSum = max(maxSum, sum);

        return maxSum;
    }
};

int main()
{

}
