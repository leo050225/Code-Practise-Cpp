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
    int result = 0;

    int traveral(TreeNode* node)
    {
        if(node == nullptr)return 2;

        int left = traveral(node->left);
        int right = traveral(node->right);

        if(left == 2 && right == 2)
            return 0;

        if(left == 0 || right == 0)
        {
            result++;
            return 1;
        }

        if(left == 1 || right == 1)
        {
            return 2;
        }

        return -1;
    }

    int minCameraCover(TreeNode* root) {
        if(traveral(root) == 0)
            result++;
        
        return result;
    }
};

int main()
{

}
