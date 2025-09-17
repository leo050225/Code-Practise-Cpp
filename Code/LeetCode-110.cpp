#include <iostream>
using namespace std;
#include<algorithm>
#include<queue>

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
    int GetDepth(TreeNode* node)
    {
        if(node == nullptr)return 0;

        int leftHeight = GetDepth(node->left);
        if(leftHeight == -1)return -1;
        int rightHeight = GetDepth(node->right);
        if(rightHeight == -1)return -1;

        if(abs(leftHeight - rightHeight) > 1)return -1;

        return 1 + max(leftHeight, rightHeight);
    }
    

    bool isBalanced(TreeNode* root) {
        if(GetDepth(root) == -1)return false;
        else return true;
    }
};

int main()
{
    
}
