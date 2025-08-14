#include<iostream>
using namespace std;
#include<algorithm>

class Solution {
public:

    void removeSpace(string &s)
    {
        int slow = 0;

        for(int fast = 0; fast<s.size(); fast++)
        {
            if(s[fast] != ' ')
            {
                if(slow != 0)s[slow++] = ' ';

                while(fast < s.size() && s[fast] != ' ')
                {
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);
    }

    string reverseWords(string s) {
        removeSpace(s);
        reverse(s.begin(), s.end());

        int start = 0;

        for(int i = 0; i<=s.size(); i++)
        {
            if(i == s.size() || s[i] ==' ')
            {
                reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
    }
};

int main()
{

}
