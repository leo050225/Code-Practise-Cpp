class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        int n = 0;
        
        vector<int> v2;

        for(int i : nums)
        {
            if(i != val)
            {
                v2.push_back(i);
                n++;
            }
        }

        nums = v2;

        return n;
    }
};
