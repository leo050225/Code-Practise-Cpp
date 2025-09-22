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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)return nullptr;

        if(root->val == key)
        {
            if(root->left == nullptr && root->right == nullptr)
            {
                delete root;
                return nullptr;
            }
            else if(root->left != nullptr && root->right == nullptr)
            {
                TreeNode* node = root->left;
                delete root;
                return node;
            }
            else if(root->left == nullptr && root->right != nullptr)
            {
                TreeNode* node = root->right;
                delete root;
                return node;
            }
            else
            {
                TreeNode* cur = root->right;
                while(cur->left != nullptr) cur = cur->left;

                cur->left = root->left;
                
                TreeNode* node = root->right;

                delete root;

                return node;
            }
        }
        if(key > root->val) root->right = deleteNode(root->right, key);

        if(key < root->val)root->left = deleteNode(root->left, key);

        return root;
    }
};

int main()
{
    
}
