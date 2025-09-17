#include <iostream>
using namespace std;
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

    int LeftTree(TreeNode* node)
    {
        if(node == nullptr)return 0;

        int leftNum = LeftTree(node->left);
        if(node->left && !node->left->left && !node->left->right)
        {
            leftNum = node->left->val;
        }

        int rightNum = LeftTree(node->right);

        return leftNum + rightNum;
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return LeftTree(root);
    }
};

int main()
{
    
}
