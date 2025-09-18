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

    int maxDepth = -1;

    int result = 0;

    void Traversal(TreeNode* node, int depth)
    {
        if(!node->left && !node->right)
        {
            if(depth > maxDepth)
            {
                maxDepth = depth;
                result = node->val;
            }
        }

        if(node->left)Traversal(node->left, depth + 1);
        if(node->right)Traversal(node->right, depth + 1);
    }

    int findBottomLeftValue(TreeNode* root) {
        Traversal(root, 1);

        return result;
    }
};

int main()
{
    
}
