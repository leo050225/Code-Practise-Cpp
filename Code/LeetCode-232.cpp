#include<iostream>
using namespace std;
#include<algorithm>
#include <stack>

class MyQueue {
public:
    stack<int> s;
    stack<int> sOut;

    MyQueue() {
        
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        if(sOut.empty())
        {
            while(!s.empty())
            {
                sOut.push(s.top());
                s.pop();
            }
        }
        int res = sOut.top();
        sOut.pop();
        return res;
    }
    
    int peek() {
        int res = this->pop();
        sOut.push(res);
        return res;
    }
    
    bool empty() {
        return s.empty() && sOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */

int main()
{

}
