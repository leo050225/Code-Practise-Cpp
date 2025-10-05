#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int count = 0;
        int result = INT_MIN;
        for(int i = 0; i<nums.size(); i++)
        {
            count += nums[i];

            if(count > result)result = count;

            if(count < 0) count = 0;
        }
        return result;
    }
};

int main()
{
}
