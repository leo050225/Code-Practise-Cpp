#include <iostream>
#include<unordered_map>
using namespace std;

struct DListNode
{
    int key, val;
    DListNode *next;
    DListNode *prev;
    DListNode() : key(0), val(0), next(nullptr), prev(nullptr){}
    DListNode(int k, int x) : key(k), val(x), next(nullptr), prev(nullptr){}
};


class LRUCache {
private:
    unordered_map<int, DListNode*> m;
    DListNode *head;
    DListNode *tail;
    int size = 0;
    int _capacity = 0;;

public:

    LRUCache(int capacity) {
        _capacity = capacity;
        head = new DListNode();
        tail = new DListNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(!m.count(key))
            return -1;
        
        DListNode *node = m[key];
        moveToHead(node);
        return node->val;
    }
    
    void put(int key, int value) {
        if(!m.count(key))
        {
            DListNode *node = new DListNode(key, value);
            m[key] = node;
            addToHead(node);
            size++;

            if(size>_capacity)
            {
                DListNode *removed = removeTail();
                m.erase(removed->key);
                delete removed;
                size--;
            }
        }
        else
        {
            DListNode *node = m[key];
            node->val = value;
            moveToHead(node);
        }
    }
    
    void addToHead(DListNode *node)
    {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    void removeNode(DListNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }
    
    void moveToHead(DListNode *node)
    {
        removeNode(node);
        addToHead(node);
    }

    DListNode *removeTail()
    {
        DListNode *node = tail->prev;
        removeNode(node);
        return node;
    }
};

int main()
{
    
}
