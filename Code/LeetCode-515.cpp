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
    vector<int> largestValues(TreeNode* root) {
        vector<int> result;
        if(root == nullptr) return result;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            int size = que.size();
            int maxNum = INT_MIN;

            for(int i = 0; i<size; i++)
            {
                TreeNode* node = que.front();
                que.pop();

                maxNum = maxNum > node->val ? maxNum : node->val;

                if(node->left)que.push(node->left);
                if(node->right)que.push(node->right);
            }
            result.push_back(maxNum);
        }
        return result;
    }
};

int main()
{

}
