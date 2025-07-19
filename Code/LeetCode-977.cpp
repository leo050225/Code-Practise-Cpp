#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) 
    {
        vector<int> v(nums.size(),0);
        int index = nums.size()-1;

        for(int i = 0 ,j = nums.size()-1; i<=j;)
        {
            if(nums[i]*nums[i] < nums[j]*nums[j])
            {
                v[index--] = nums[j]*nums[j];
                j--;
            }
            else
            {
                v[index--] = nums[i]*nums[i];
                i++;
            }
        }
        return v;
    }
};
