#include<iostream>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        int record[26] = {0};

        for(int n1 = 0; n1<s.size(); n1++)
        {
            record[s[n1] - 'a']++;
        }

        for(int n2 = 0; n2<t.size(); n2++)
        {
            record[t[n2] - 'a']--;
        }

        for(int n3 = 0; n3<sizeof(record)/sizeof(int); n3++)
        {
            if(record[n3] != 0) return false;
        }

        return true;
    }
};

int main()
{
    Solution s;
    cout<<s.isAnagram("eaa","aea");

    return 0;
}
