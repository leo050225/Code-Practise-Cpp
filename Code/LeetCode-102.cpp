#include <iostream>
#include<vector>
#include<queue>
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root)return{};

        vector<vector<int>> result;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty())
        {
            int levelSize = que.size();
            vector<int> currentLevel;
            currentLevel.reserve(levelSize);//預先留空間

            for(int i = 0; i<levelSize; ++i)
            {
                TreeNode* node = que.front();
                que.pop();

                currentLevel.push_back(node->val);
                
                if(node->left)
                    que.push(node->left);
                if(node->right)
                    que.push(node->right);   
            }
            result.push_back(move(currentLevel));//減少身拷貝開銷
        }
        return result;
    }
};

int main()
{
    
}
