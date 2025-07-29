#include<iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dunnyhead = new ListNode(0);
        dunnyhead->next = head;
        ListNode *fast = dunnyhead;
        ListNode *slow = dunnyhead;
        n++;
        while (n-- && fast!=nullptr)
        {
            fast = fast->next;
        }

        while (fast!=nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode *tmp = slow->next;
        slow->next = slow->next->next;
        delete tmp;
        tmp = nullptr;
        
        return dunnyhead->next;
    }
};

int main()
{
    return 0;
}
