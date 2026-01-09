#include <iostream>
#include<vector>
#include<algorithm>
#include<string.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *dummyHead = new ListNode(0);
        dummyHead->next = head;

        ListNode *mid = midNode(dummyHead);
        ListNode *n1 = reverList(mid->next);
        ListNode *n2 = head;

        while(n1 != nullptr)
        {
            if(n1->val != n2->val)
                return false;
            n1 = n1->next;
            n2 = n2->next;
        }

        mid->next = reverList(n1);//把原數據變回來
        return true;
    }

    ListNode *midNode(ListNode *head)
    {
        ListNode *fast = head;
        ListNode *slow = head;
        
        while(fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode *reverList(ListNode *haed)
    {
        if(!haed || !haed->next)
            return haed;

        ListNode *newhead = reverList(haed->next);
        haed->next->next = haed;
        haed->next = nullptr;
        return newhead;
    }
};

int main()
{
    
}
