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

//雙指針
class Solution1 {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head;
        ListNode *pre = nullptr;
        while (cur)
        {
            ListNode *tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }
};

//遞歸
class Solution2 {
public:
    ListNode* reverse(ListNode *cur, ListNode *pre){
        if(cur==nullptr)return pre;
        ListNode *tmp = cur->next;
        cur->next = pre;
        return reverse(tmp,cur);
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(head,nullptr);
    }
};

int main()
{
    return 0;
}
