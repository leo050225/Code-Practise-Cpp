#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    pair<ListNode*, ListNode*> myReverse(ListNode *head, ListNode *tail)
    {
        ListNode *prev = tail->next;
        ListNode *p = head;

        while(prev != tail)
        {
            ListNode *nex = p->next;
            p->next = prev;
            prev = p;
            p = nex;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummyhead = new ListNode(0,head);
        ListNode *pre = dummyhead;

        while(head)
        {
            ListNode *tail = pre;

            for(int i = 0; i<k; i++)
            {
                tail = tail->next;
                if(tail == nullptr)
                    return dummyhead->next;
            }
            
            ListNode *nex = tail->next;
            tie(head, tail) = myReverse(head, tail);

            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }

        return dummyhead->next;
    }
};

int main()
{
    
}
