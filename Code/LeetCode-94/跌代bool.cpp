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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<pair<TreeNode*, bool>> st;
        if(root != nullptr)
            st.push(make_pair(root, false));

        while (!st.empty())
        {   
            auto node = st.top().first;
            auto visited = st.top().second;
            st.pop();

            if(visited)
            {
                result.push_back(node->val);
                continue;
            }

            if(node->right) st.push(make_pair(node->right, false));
            
            st.push(make_pair(node, true));
            
            if(node->left) st.push(make_pair(node->left, false));
                
        }

    return result;
    }
};

int main()
{

}
