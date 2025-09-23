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
    TreeNode* Traversal(vector<int>& nums, int left, int right)
    {
        if(left > right)return nullptr;

        int mid = (left + right) / 2;

        TreeNode* node = new TreeNode(nums[mid]);

        node->left = Traversal(nums, left, mid - 1);
        node->right = Traversal(nums, mid + 1, right);
    
        return node;
    }   

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return Traversal(nums, 0, nums.size() - 1);
    }
};

int main()
{
    
}
