#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>


struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0) , next(NULL){}
    ListNode(int x) : val(x), next(NULL){}
    ListNode(ListNode *node, int x) : val(x), next(node){}
};

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        if(head == nullptr) return nullptr;

        if(head->val == val)
        {
            ListNode *nowNode = removeElements(head->next,val);
            delete head;
            return nowNode;
        }
        else
        {
            head->next = removeElements(head->next,val);
            return head;
        }
    }
};

int main()
{

}
