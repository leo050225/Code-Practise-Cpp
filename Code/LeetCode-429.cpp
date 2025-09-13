#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> result;
        if(root == nullptr)return result;

        queue<Node*> que;
        que.push(root);

        while(!que.empty())
        {
            int size = que.size();
            vector<int> vec;
            for(int i = 0; i<size; i++)
            {
                Node* node = que.front();
                que.pop();

                vec.push_back(node->val);

                if(!node->children.empty())
                {
                    for(Node* i : node->children)
                    {
                        que.push(i);
                    }
                }
            }
            result.push_back(vec);
        }
        return result;
    }
};

int main()
{

}
