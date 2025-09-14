#include<iostream>
using namespace std;
#include<vector>
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
    int maxDepth(TreeNode* root) {
        int count = 0;
        
        if(root == nullptr)return count;

        queue<TreeNode*> que;
        que.push(root);



        while(!que.empty())
        {
            int size = que.size();
            
            for(int i = 0; i<size; i++)
            {
                TreeNode* node = que.front();
                que.pop();

                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
            count++;
        }
        return count;
    }
};

int main()
{

}
