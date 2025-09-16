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

    bool compare(TreeNode* left, TreeNode* right)
    {
        if(left == nullptr && right == nullptr)return true;
        else if(left == nullptr && right != nullptr)return false;
        else if(left != nullptr && right == nullptr)return false;
        else if(left->val != right->val)return false;

        bool outSide = compare(left->left, right->right);
        bool inSide = compare(left->right, right->left);
        bool isSame = outSide && inSide;
        
        return isSame;
    }

    bool isSymmetric(TreeNode* root) {
        if(root==nullptr)return true;

        return compare(root->left, root->right);
    }
};

int main()
{
    
}
