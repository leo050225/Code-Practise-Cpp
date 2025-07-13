#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int start = 0;
        int end = 0;
        int sum = 0;
        int minLen = INT_MAX;

        while (end<nums.size())
        {
            sum+=nums[end];
            while (sum>=target)
            {
                minLen = min(minLen,end - start + 1);
                sum-=nums[start];
                start++;
            }
            end++;
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};

int main()
{
    Solution s;
    vector<int> v{1,2,3,4,5};

    int num = s.minSubArrayLen(11,v);

    cout<<num<<endl;
}
