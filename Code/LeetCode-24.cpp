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

int main()
{
    
}
