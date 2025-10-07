#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    static bool cmp(int a, int b)
    {
        return abs(a) > abs(b);
    }

    int largestSumAfterKNegations(vector<int>& nums, int k) {

        int sum = 0;

        sort(nums.begin(), nums.end(), cmp);

        for(int i = 0; i<nums.size(); i++)
        {
            if(nums[i] < 0 && k > 0)
            {
                k--;
                nums[i] *= -1;
            }
        }

        if(k%2 == 1)nums[nums.size() - 1] *= -1;

        for(int i : nums)
        {
            sum += i;
        }

        return sum;
    }
};

int main()
{
    
}
