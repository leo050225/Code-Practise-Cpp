#include<iostream>
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
    int minValue = INT_MAX;

    TreeNode* pre = nullptr;
    
    void Traversal(TreeNode* node)
    {
        if(node == nullptr)return;

        Traversal(node->left);

        if(pre != nullptr && abs(node->val - pre->val) < minValue)
            minValue = abs(node->val - pre->val);

        pre = node;

        Traversal(node->right);

        return;
    }

    int getMinimumDifference(TreeNode* root) {
        Traversal(root);

        return minValue;
    }
};

int main()
{
}
