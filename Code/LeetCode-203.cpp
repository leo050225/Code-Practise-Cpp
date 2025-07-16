/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// class Solution {
// public:
//     ListNode* removeElements(ListNode* head, int val) 
//     {
//         if(head == nullptr)return head;

//         head->next = removeElements(head->next,val);

//         return head->val == val ? head->next : head;
//     }
// };

class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) 
    {
        ListNode *dummyHead = new ListNode(0,head);
        ListNode *temp = dummyHead;

        while (temp->next!=nullptr)
        {
            if(temp->next->val == val)
            {
                temp->next = temp->next->next;
            }
            else
            {
                temp = temp->next;
            }
        }
        return dummyHead->next;
    }
};
