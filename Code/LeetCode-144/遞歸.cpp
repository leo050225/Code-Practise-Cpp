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

    void Treeselc(vector<int>& result, TreeNode* node)
    {   
        if(node == nullptr) return;

        result.push_back(node->val);

        Treeselc(result, node->left);
        Treeselc(result, node->right);

        return;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;

        Treeselc(result, root);

        return result;
    }
};

int main()
{
    
}
