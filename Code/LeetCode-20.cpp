#include <iostream>
using namespace std;
#include<algorithm>
#include<stack>

class Solution {
public:
    stack<char> st;

    bool isValid(string s) {

        if(s.size() % 2 != 0)return false;

        for(int i = 0; i<s.size(); i++)
        {
            if(s[i] == '[') st.push(']');

            else if(s[i] == '{') st.push('}');

            else if(s[i] == '(') st.push(')');

            else if(st.empty() || st.top()!=s[i]) return false;

            else st.pop();//s[i] == st.top()
        }

        return st.empty();
    }
};

int main()
{

}
