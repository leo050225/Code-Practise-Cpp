#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int left = 0;
        int right = nums.size()-1;
        int middle = 0;
        
        while (left<=right)
        {
            middle = left+((right-left)>>1);

            if(nums[middle] < target)
            {
                left = middle + 1;
            }
            else if(nums[middle] > target)
            {
                right = middle - 1;
            }
            else
            {
                return middle;
            }
        }
        return -1;
    }
};

int main()
{
    Solution s;
    vector<int> v{1,2,6,3,4,5};
    cout<<s.search(v,6)<<endl;
}
