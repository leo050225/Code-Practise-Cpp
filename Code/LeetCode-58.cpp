#include <iostream>
using namespace std;
#include<algorithm>
#include<vector>

class Solution {
public:
    int lengthOfLastWord(string s) 
    {
        int n = 0;
        int len = s.length() - 1;

        while (len>=0 && s[len] ==' ') len--;
        

        while (len>=0 && s[len]!=' ')
        {
            n++;
            len--;
        }
        
        return n;     
    }
};


int main()
{
    Solution s;
    cout<<s.lengthOfLastWord("   fly me   to   the moon  ")<<endl;
}
