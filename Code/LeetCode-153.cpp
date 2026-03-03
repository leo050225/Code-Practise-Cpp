#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();

        int left = 0;
        int right = n - 1;

        if(nums[left] <= nums[right])
        {
            return nums[left];
        }

        while (left<=right)
        {
            if(nums[left] <= nums[right])
            {
                return nums[left];
            }
            
            int mid = left + (right - left) / 2;

            if(nums[mid] > nums[right])
            {
                left = mid + 1;
            }
            else
            {
                right = mid;
            }
        }
        return nums[left];
    }
};

int main()
{

}
