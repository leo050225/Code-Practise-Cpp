#include<iostream>
using namespace std;
#include<vector>

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
    TreeNode* pre = nullptr;
    vector<int> result;
    int count = 0;
    int maxCount = 0;

    void Traversal(TreeNode* node)
    {
        if(node == nullptr)return;

        Traversal(node->left);

        if(pre == nullptr)
            count = 1;
        else if(pre->val == node->val)
            count++;
        else
            count = 1;

        pre = node;

        if(count == maxCount)
            result.push_back(node->val);
        if(count > maxCount)
        {
            maxCount = count;
            result.clear();
            result.push_back(node->val);  
        }

        Traversal(node->right);
        return;
    }

    vector<int> findMode(TreeNode* root) {
        Traversal(root);
        return result;
    }
};

int main()
{
}
