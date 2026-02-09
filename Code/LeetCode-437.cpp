#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

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
    int pathSum(TreeNode* root, int targetSum) {

        unordered_map<long long, int> m;

        m[0] = 1;
        
        return dfs(root, 0, targetSum, m);
    }

    int dfs(TreeNode* node, long long curSum, int target, unordered_map<long long, int>& m)
    {
        if(!node)
        {
            return 0;
        }

        int count = 0;

        curSum += node->val;

        if(m.find(curSum - target) != m.end())
        {
            count += m[curSum - target];
        }

        m[curSum]++;

        count += dfs(node->left, curSum, target, m);
        count += dfs(node->right, curSum, target, m);
        
        m[curSum]--;

        return count;
    }
};

int main()
{
    
}
