#include <iostream>
using namespace std;
#include<vector>
#include<unordered_set>

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void BackTracking(vector<int>& nums, int index)
    {
        if(path.size() >= 2)
        {
            result.push_back(path);
        }

        unordered_set<int> uSet;

        for(int i = index; i<nums.size(); i++)
        {
            if((!path.empty() && nums[i] < path.back()) || uSet.find(nums[i]) != uSet.end())
                continue;
            
            path.push_back(nums[i]);
            uSet.insert(nums[i]);
            BackTracking(nums, i + 1);
            path.pop_back();
        }
        return;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        BackTracking(nums, 0);
        return result;
    }
};

int main()
{
    
}
