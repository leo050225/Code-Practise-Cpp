#include<iostream>
using namespace std;
#include<queue>
#include<vector>


class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        
        if(root == nullptr)return nullptr;

        queue<Node*> que;

        que.push(root);

        Node* node;
        Node* nodeCur;

        while(!que.empty())
        {
            int size = que.size();

            for(int i = 0; i<size; i++)
            {      
                if(i == 0)
                {
                    nodeCur = que.front();
                    que.pop();
                    node = nodeCur;
                }
                else
                {
                    nodeCur = que.front();
                    que.pop();
                    node->next = nodeCur;
                    node = nodeCur;
                }

                if(nodeCur->left)que.push(nodeCur->left);
                if(nodeCur->right)que.push(nodeCur->right);
            }
            node->next = nullptr;
        }
        return root;
    }
};

int main()
{

}
