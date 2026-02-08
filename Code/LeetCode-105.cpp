#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// class Node {
// public:
//     int val;
//     Node* next;
//     Node* random;

//     Node(int _val) {
//         val = _val;
//         next = NULL;
//         random = NULL;
//     }
// };

// struct ListNode {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
private:
    // 用節點值找到中序數組中節點的位置
    unordered_map<int,int> m;
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        for(int i = 0; i<n; i++)
        {
            m[inorder[i]] = i;
        }

        return helper(preorder, 0, n-1, 0, n-1);
    }

    TreeNode* helper(const vector<int>& preorder, int pre_left, int pre_right, int in_left, int in_right)
    {
        if(pre_left > pre_right)
        {
            return nullptr;
        }

        // 構造根節點
        int rootval = preorder[pre_left];
        TreeNode* root = new TreeNode(rootval);
        
        // 找到在中序數組中當前根節點的位置
        int in_root_index = m[rootval];
        
        // 找到中序數組左子樹的數量
        int size_left_subtree = in_root_index - in_left;
        
        // 前序左子樹 pre_left + 1 ~ pre_left + size_left_subtree
        // 中序左子樹 in_left ~ in_root_index - 1
        root->left = helper(preorder, pre_left + 1, pre_left + size_left_subtree, in_left, in_root_index - 1);

        // 前序右子樹 pre_left + size_left_subtree + 1 ~ pre_right
        // 中序右子樹 in_root_index + 1 ~ in_right;
        root->right = helper(preorder, pre_left + size_left_subtree + 1, pre_right, in_root_index + 1, in_right);

        return root;
    }
};

int main()
{
    
}
