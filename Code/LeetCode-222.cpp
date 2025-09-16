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

    int Count(TreeNode* node)
    {
        if(node == nullptr) return 0;

        TreeNode* left = node->left;
        TreeNode* right = node->right;

        int leftCount = 0;
        int rightCount = 0;

        while(left)
        {
            left = left->left;
            leftCount++;
        }

        while(right)
        {
            right = right->right;
            rightCount++;
        }

        if(leftCount == rightCount)
        {
            return (2 << leftCount) - 1;
        }

        return Count(node->left) + Count(node->right) + 1;
    }

    int countNodes(TreeNode* root) {
        return Count(root);
    }
};

int main()
{
    
}
