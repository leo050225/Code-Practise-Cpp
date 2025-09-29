#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;

    void BackTracking(vector<int>& nums, int index)
    {
        result.push_back(path);

        if(index >= nums.size())
            return;

        for(int i = index; i<nums.size(); i++)
        {
            path.push_back(nums[i]);
            BackTracking(nums, i + 1);
            path.pop_back();
        }

        return;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        BackTracking(nums, 0);
        return result;
    }
};

int main()
{
}
