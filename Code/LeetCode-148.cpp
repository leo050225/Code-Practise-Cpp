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
    ListNode* sortList(ListNode* head) {
        int len = 0;
        ListNode *curr = head;
        while(curr)
        {
            len++;
            curr = curr->next;
        }

        ListNode dummyhead(0);
        dummyhead.next = head;

        for(int sz = 1; sz < len; sz <<= 1)
        {
            ListNode *prev = &dummyhead;
            curr = dummyhead.next;

            while(curr)
            {
                ListNode *left = curr;//剩下數組前半部分 有sz個
                ListNode *right = split(left, sz);//前半部分後面sz個的數組

                curr = split(right, sz);//紀錄後半部分後面還沒整理的節點

                pair<ListNode*, ListNode*> merged = merge(left, right);//前後組排序
                prev->next = merged.first;//紀錄整組節點 + 新整理好的
                prev = merged.second;//把指針指向尾端
            }
        }
        return dummyhead.next;
    }

    // 切斷從head開始後第step的節點
    ListNode *split(ListNode *head, int step)
    {
        if(!head)return nullptr;

        //找到頭節點後step個部分
        for(int i = 0; head->next && i < step - 1; i++)
        {
            head = head->next;
        }

        ListNode *rest = head->next;//指向當前頭節點後step後的節點
        head->next = nullptr;//斷掉連結
        return rest;//返回數組的後半部分
    }

    //結合兩個鏈表 升序排序
    pair<ListNode*, ListNode*> merge(ListNode *l1, ListNode *l2)
    {
        ListNode dummyhead(0);
        ListNode *tail = &dummyhead;

        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                tail->next = l1;
                l1 = l1->next;
            }    
            else
            {
                tail->next = l2;
                l2 = l2->next;
            }
            tail = tail->next;
        }

        tail->next = l1? l1 : l2;
        while(tail->next)tail = tail->next;

        return{dummyhead.next, tail};
    };
};

int main()
{
    
}
