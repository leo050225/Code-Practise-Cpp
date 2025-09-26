#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    vector<vector<int>> result;
    vector<int> path;

    void BackTracking(vector<int>& candidates, int target, int sum, int index)
    {
        if(sum > target) return;
        if(sum == target)
        {
            result.push_back(path);
            return;
        }

        for(int i = index; i<candidates.size(); i++)
        {
            if(candidates[i] > target)break;
            path.push_back(candidates[i]);
            BackTracking(candidates, target, sum + candidates[i], i);
            path.pop_back();
        }
        
        return;
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        BackTracking(candidates, target, 0, 0);
        return result;
    }
};

int main()
{
}
