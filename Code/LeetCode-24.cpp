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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr || head->next == nullptr)
            return head;

        ListNode *newhaed = head->next;//指向頭節點後面節點

        head->next = swapPairs(newhaed->next);//用下一輪兩個節點遞歸 返回結果給當前節點

        newhaed->next = head;//當前節點變成新頭節點的後節點
        
        return newhaed;//返回新頭節點
    }
};

// 跌代
// class Solution {
// public:
//     ListNode* swapPairs(ListNode* head) {
//         ListNode *dummyhaed = new ListNode(0,head);

//         ListNode *temp = dummyhaed;
//         ListNode *node1;
//         ListNode *node2;

//         while(temp->next != nullptr && temp->next->next != nullptr)
//         {
//             node1 = temp->next;
//             node2 = temp->next->next;

//             temp->next = node2;
//             node1->next = node2->next;
//             node2->next = node1;

//             temp = node1;
//         }

//         temp = dummyhaed->next;
//         delete dummyhaed;
//         return temp;
//     }
// };

int main()
{
    
}
