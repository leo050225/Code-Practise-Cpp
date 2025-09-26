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

    

    void BackTracking(vector<int>& candidates, int target, int sum, int index, vector<bool>& used)
    {
        if(sum > target)return;
        if(sum == target)
        {
            result.push_back(path);
            return;
        }

        for(int i = index; i<candidates.size(); i++)
        {
            if(i != 0 && candidates[i] == candidates[i - 1] && used[i - 1] == false) continue;

            path.push_back(candidates[i]);
            used[i] = true;
            BackTracking(candidates, target, sum + candidates[i], i + 1, used);
            path.pop_back();
            used[i] = false;
        }

        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<bool> used(candidates.size(), false);
        BackTracking(candidates, target, 0, 0, used);
        return result;
    }
};

int main()
{
}
