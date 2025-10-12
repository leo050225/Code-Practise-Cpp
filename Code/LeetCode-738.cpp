#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);

        int index = s.size();
        
        for(int i = s.size() - 1; i > 0; i--)
        {
            if(s[i - 1] > s[i])
            {
                index = i;
                s[i - 1]--;
            }
        }

        for(int i = index; i<s.size(); i++)
        {
            s[i] = '9';
        }
        
        return stoi(s);
    }
};

int main()
{

}
