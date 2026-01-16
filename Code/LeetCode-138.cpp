#include <iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {

        if(head==nullptr)
            return nullptr;

        Node *curr = head;
        Node *nex = curr;
        while(curr != nullptr)
        {
            nex = nex->next;
            curr->next = new Node(curr->val);
            curr->next->next = nex;
            curr = nex;
        }

        curr = head;

        while(curr != nullptr)
        {
            if(curr->random != nullptr)
                curr->next->random = curr->random->next;
            curr = curr->next->next;
        }

        curr = head->next;
        Node *newhead = head->next;
        Node *oldhead = head;
        while(oldhead != nullptr)
        {
            oldhead->next = oldhead->next->next;
            if(curr->next != nullptr)
                curr->next = curr->next->next;
                
            curr = curr->next;
            oldhead = oldhead->next;
        }

        return newhead;
    }
};

int main()
{
    
}
