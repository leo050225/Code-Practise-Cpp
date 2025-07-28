#include <iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include <climits>




struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
        ListNode *dunnyhead = new ListNode(0);
        dunnyhead->next = head;
        ListNode *cur = dunnyhead;

        while (cur->next != nullptr && cur->next->next != nullptr)
        {
            ListNode *tmp = cur->next;
            ListNode *tmp1 = cur->next->next->next;
            cur->next = cur->next->next;
            cur->next->next = tmp;
            tmp->next = tmp1;
            cur = cur->next->next;
        }
        
        return dunnyhead->next;
    }
};

int main()
{
    return 0;
}
