#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
  };
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if(headA == nullptr || headB == nullptr)
            return nullptr;

        ListNode *pua = headA;
        ListNode *pub = headB;
    
        while(pua != pub)
        {
            pua = pua == nullptr ? headB : pua->next;
            pub = pub == nullptr ? headA : pub->next;
        }
        return pua;
    }
};

int main()
{
    
}
