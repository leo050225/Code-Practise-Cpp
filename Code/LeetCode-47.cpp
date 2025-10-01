#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void BackTracking(vector<int>& nums, vector<bool>& used)
    {
        if(path.size() == nums.size())
        {
            result.push_back(path);
        }

        for(int i = 0; i < nums.size(); i++)
        {
            if(i > 0 && nums[i] == nums[i - 1] && used[i - 1] == false)
                continue;
            
            if(used[i] == false)
            {
                path.push_back(nums[i]);
                used[i] = true;
                BackTracking(nums, used);
                path.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        sort(nums.begin(), nums.end());
        BackTracking(nums, used);
        return result;    
    }
};

int main()
{
    
}
