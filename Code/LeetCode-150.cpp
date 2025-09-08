#include <iostream>
using namespace std;
#include<stack>
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> s;
        
        for(long long i = 0; i < tokens.size(); i++)
        {
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/")
            {
                long long n1 = s.top();//後放進去的
                s.pop();
                long long n2 = s.top();//先放進去的
                s.pop();

                if(tokens[i] == "+") s.push(n2 + n1);
                if(tokens[i] == "-") s.push(n2 - n1);
                if(tokens[i] == "*") s.push(n2 * n1);
                if(tokens[i] == "/") s.push(n2 / n1);
            }
            else
            {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};

int main()
{
    
}
