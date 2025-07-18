class Solution {
public:
    int removeElement(vector<int>& nums, int val)
    {
        int slowindex = 0;
        for(int fastIndex = 0; fastIndex<nums.size(); fastIndex++)
        {
            if(nums[fastIndex] != val)
            {
                nums[slowindex] = nums[fastIndex];
                slowindex++;
            }
        }
        return slowindex;
    }
};
