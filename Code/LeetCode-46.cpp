#include <iostream>
using namespace std;
#include<vector>
#include<unordered_set>

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

        for(int i = 0; i<nums.size(); i++)
        {
            if(used[i] == true) continue;
            path.push_back(nums[i]);
            used[i] = true;
            BackTracking(nums, used);
            path.pop_back();
            used[i] = false;
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false);
        BackTracking(nums,used);
        return result;
    }
};

int main()
{
    
}
