#include<iostream>
using namespace std;
#include<vector>
#include<stack>
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> s;

        s.push(root);

        while(!s.empty())
        {
            TreeNode* t = s.top();
            s.pop();

            if(t != nullptr)
                result.push_back(t->val);
            else
                continue;
            s.push(t->left);
            s.push(t->right);
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

int main()
{

}
