#include<iostream>
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

    TreeNode* pre;

    bool Traversal(TreeNode* node)
    {
        if(node == nullptr)return true;

        bool left = Traversal(node->left);

        if(pre != nullptr && pre->val >= node->val)
            return false;
        pre = node;

        bool right = Traversal(node->right);

        return left && right;
    }

    bool isValidBST(TreeNode* root) {
        return Traversal(root);
    }
};

int main()
{
}
