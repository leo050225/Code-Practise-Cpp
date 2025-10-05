#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size() == 1)return 1;

        int pre = 0;
        int cur = 0;
        int result = 1;

        for(int i = 0; i<nums.size() - 1; i++)
        {
            cur = nums[i + 1] - nums[i];

            if((pre >= 0 && cur <0) || (pre <= 0 && cur > 0))
            {
                result++;
                pre = cur;
            }
        }

        return result;
    }
};

int main()
{
}
