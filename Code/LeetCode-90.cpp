#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;
    
    void BackTracking(vector<int>& nums, int index, vector<bool>& used)
    {
        result.push_back(path);

        for(int i = index; i<nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i - 1] && !used[i - 1])
                continue;
            path.push_back(nums[i]);
            used[i] = true;
            BackTracking(nums, i + 1, used);
            path.pop_back();
            used[i] = false;
        }
        return;
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        BackTracking(nums,0,used);
        return result;
    }
}; 

int main()
{
    
}
