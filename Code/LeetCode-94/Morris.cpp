#include <iostream>
#include<vector>
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
    vector<int> inorderTraversal(TreeNode* root) {
       vector<int> res;
       TreeNode *predecessor = nullptr;//前驅
       
        while(root)
        {
            // 有左孩子
            if(root->left)
            {
                //找到左子樹 最右下節點 找到當前節點前驅
                predecessor = root->left;
                while(predecessor->right && predecessor->right != root)
                {
                    predecessor = predecessor->right;
                }

                //前驅沒有後繼
                if(!predecessor->right)
                {
                    predecessor->right = root;//如果是當前節點的前驅 將前驅的後繼指向當前節點
                    root = root->left;//當前節點指針往左下
                }
                //前驅有後繼 代表前驅記錄過了
                else
                {
                    res.push_back(root->val);//紀錄當前節點
                    predecessor->right = nullptr;// 斷掉前驅和當前節點的臨時路線
                    root = root->right;//指向後繼節點
                }
            }
            //沒有左節點 代表沒有前驅 紀錄當前節點 訪問右節點
            else
            {
                res.push_back(root->val);//紀錄當前節點
                root = root->right;//指向後繼節點
            }
        }
        return res;
    }   
};

int main()
{
    
}
