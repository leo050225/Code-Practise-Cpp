#include <iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include <climits>

class MyLinkedList 
{
public:
    struct LinkNode
    {
        int val;
        LinkNode *next;
        LinkNode(int x) : val(x), next(NULL){}
    };
private:
    LinkNode *head;
    int _size;
public:
    MyLinkedList() 
    {
        head = new LinkNode(0);
        _size = 0;
    }
    
    int get(int index) //获取链表第index个节点的数值
    {
        if(index >= _size || index<0)return -1;
        
        LinkNode *cur = head->next;

        while (index--)
        {
            cur = cur->next;
        }

        return cur->val;
    }
    
    //// 在链表最前面插入一个节点，插入完成后，新插入的节点为链表的新的头结点
    void addAtHead(int val) //在链表的最前面插入一个节点
    {
        LinkNode *newNode = new LinkNode(val);
        newNode->next = head->next;
        head->next = newNode;
        _size++;
    }
    
    void addAtTail(int val) //在链表的最后面插入一个节点
    {
        LinkNode *newNode = new LinkNode(val);
        LinkNode *cur = head;
        while(cur->next != nullptr)
        {
            cur = cur->next;
        }
        cur->next = newNode;
        _size++;
    }
    
    void addAtIndex(int index, int val) //在链表第index个节点前面插入一个节点
    {
        if(index > _size)return;
        if(index < 0)index = 0;
        LinkNode *newNode = new LinkNode(val);
        LinkNode *cur = head;
        while (index--)
        {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
        _size++;
        
    }
    
    void deleteAtIndex(int index) //删除链表的第index个节点
    {
        if(index > _size-1 || index<0)return;

        LinkNode *cur = head;

        while (index--)
        {
            cur = cur->next;
        }
        LinkNode *tmp = cur->next;
        cur->next = cur->next->next;
        delete tmp;
        tmp = nullptr;
        _size--;
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

int main()
{
    return 0;
}
