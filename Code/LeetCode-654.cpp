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
    TreeNode* Traversal(vector<int>& nums, int left, int right)//左閉右開
    {
        if(left >= right)return nullptr;

        int maxValueIndex = left;
        
        for(int i = left; i < right; i++)
        {
            if(nums[i] > nums[maxValueIndex]) maxValueIndex = i;
        }

        TreeNode* node = new TreeNode(nums[maxValueIndex]);

        node->left = Traversal(nums, left, maxValueIndex);

        node->right = Traversal(nums, maxValueIndex + 1, right);

        return node;
    }

    public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return Traversal(nums, 0, nums.size());
    }
};

int main()
{
}
