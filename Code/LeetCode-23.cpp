#include <iostream>
#include<vector>
#include<queue>
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
    
    struct  Status
    {
        int val;
        ListNode *ptr;

        bool operator < (const Status &rhs) const
        {
            return val > rhs.val;
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<Status> que;

        for(auto node : lists)
        {
            if(node) que.push({node->val, node});
        }

        ListNode dummy(0), *tail = &dummy;
        
        while(!que.empty())
        {
            auto node = que.top();
            que.pop();
            tail->next = node.ptr;
            tail = tail->next;
            if(node.ptr->next) que.push({node.ptr->next->val, node.ptr->next});
        }
        return dummy.next;
    }
};

int main()
{
    
}
