#include <iostream>
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
private:
    int maxNum = INT_MIN;
public:
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return maxNum;
    }

    int dfs(TreeNode* node)
    {
        if(!node)
        {
            return 0;
        }

        int left = max(dfs(node->left), 0);
        int right = max(dfs(node->right), 0);
    
        maxNum = max(maxNum, node->val + left + right);
    
        return node->val + max(left, right);
    }
};

int main()
{
    
}
