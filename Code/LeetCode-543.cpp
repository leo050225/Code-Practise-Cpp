#include <iostream>
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
    int ans;
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        dist(root);
        return ans - 1;
    }

    int dist(TreeNode *node)
    {
        if(!node)
            return 0;
        int L = dist(node->left);
        int R = dist(node->right);
        ans = max(ans, L + R + 1);
        return max(L, R) + 1;
    }
};

int main()
{
    
}
