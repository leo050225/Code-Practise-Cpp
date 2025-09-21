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
    TreeNode* Traversal(TreeNode* node, TreeNode* p, TreeNode* q)
    {
        if(node == nullptr) return nullptr;
        if(node == p || node == q) return node;

        TreeNode* left = Traversal(node->left, p, q);
        TreeNode* right = Traversal(node->right, p, q);
    
        if(left != nullptr && right != nullptr) return node;

        if(left != nullptr && right == nullptr) return left;
        else if(left == nullptr && right != nullptr) return right;
        else return nullptr;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return Traversal(root,p,q);
    }
};

int main()
{
}
