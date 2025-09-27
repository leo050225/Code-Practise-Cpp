#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {

    vector<vector<string>> result;
    vector<string> path;

    void BackTracking(const string& s, int index)
    {
        if(index >= s.size())
        {
            result.push_back(path);
            return;
        }

        for(int i = index; i<s.size(); i++)
        {
            if(isPalindrome(s, index, i))
            {
                string str = s.substr(index, i - index + 1);
                path.push_back(str);
            }
            else
            {
                continue;
            }
            BackTracking(s, i + 1);
            path.pop_back();
        }
        return;
    }

    bool isPalindrome(const string& s, int start, int end)
    {
        for(int i = start, j = end; i < j; i++, j--)
        {
            if(s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }

public:
    vector<vector<string>> partition(string s) {
        BackTracking(s,0);
        return result;
    }
};

int main()
{
}
