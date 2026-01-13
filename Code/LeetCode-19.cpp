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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode *dummyhead = new ListNode(0,head);
        ListNode *slow = dummyhead;
        ListNode *fast = dummyhead;

        while(n--)
            fast = fast->next;

        while(fast->next != nullptr)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *temp = slow->next;
        slow->next = slow->next->next;
        delete temp;
        slow = dummyhead->next;
        delete(dummyhead);
        return slow;
    }
};

int main()
{
    
}
