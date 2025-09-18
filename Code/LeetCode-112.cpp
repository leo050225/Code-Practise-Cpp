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

    bool Traversal(TreeNode* node, int count)
    {
        if(!node->left && !node->right)
        {
            if(count == node->val)return true;
            else return false;
        }

        if(node->left && Traversal(node->left, count - node->val))return true;

        if(node->right && Traversal(node->right, count - node->val))return true;
        
        return false;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == nullptr)return false;
        return Traversal(root, targetSum);
    }
};

int main()
{
    
}
