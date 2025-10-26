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
    int rob(TreeNode* root) {
        vector<int> dp = rob2(root);

        return max(dp[0], dp[1]);
    }

    vector<int> rob2(const TreeNode *node)
    {
        if(node == nullptr)return vector<int>{0,0};

        vector<int> left = rob2(node->left);
        vector<int> right = rob2(node->right);

        int val1 = node->val + left[0] + right[0];
        int val2 = max(left[0], left[1]) + max(right[0], right[1]);

        return vector<int>{val2, val1};
    }
};

int main()
{
    
}
