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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cura = headA;
        ListNode *curb = headB;

        while(cura!=curb)
        {
            cura = cura != nullptr ? cura->next : headB;
            curb = curb != nullptr ? curb->next : headA;
        }

        return cura;
    }
};

int main()
{
    return 0;
}
