#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
//兩個節點都走一樣的步數 如果有相交最後會碰到一起 沒有的話兩個都會等於NULL
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
