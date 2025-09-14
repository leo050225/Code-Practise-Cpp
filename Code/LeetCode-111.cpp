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
    int minDepth(TreeNode* root) {
        if(root == nullptr)return 0;
        
        queue<TreeNode*> que;
        que.push(root);

        int result = INT_MAX;

        int floor = 0;

        while(!que.empty())
        {
            int size = que.size();

            floor++;

            for(int i = 0; i<size; i++)
            {
                TreeNode* node = que.front();
                que.pop();

                if(!node->left && ! node->right)
                {
                    result = result < floor ? result : floor;
                }

                if(node->left)que.push(node->left);
                if(node->right)que.push(node->right);
            }
        }
        return result;
    }
};

int main()
{

}
