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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *dummyhaed = new ListNode(0);
        ListNode *cur = dummyhaed;
        int n1 = 0;
        int n2 = 0;
        int carry = 0;
        int sum = 0;

        while(l1!=nullptr || l2!=nullptr)
        {
            n1 = l1!=nullptr ? l1->val : 0;
            n2 = l2!=nullptr ? l2->val : 0;
        
            sum = n1 + n2 + carry;

            cur->next = new ListNode(sum%10);
            cur = cur->next;

            carry = sum/10;
            
            if(l1!=nullptr)
                l1 = l1->next;
            if(l2!=nullptr)
                l2 = l2->next;
        }
        
        if(carry > 0)
            cur->next = new ListNode(carry);
        cur = dummyhaed->next;
        delete dummyhaed;
        return cur;    
    }
};

int main()
{
    
}
