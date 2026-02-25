#include<iostream>
using namespace std;

class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;

    vector<vector<string>> partition(string s) {
        backtrack(s, 0);
        return res;
    }

    void backtrack(const string& s, int index)
    {
        if(index >= s.size())
        {
            res.push_back(path);
            return;
        }

        for(int i = index; i<s.size(); i++)
        {
            if(isPalindrome(s, index, i))
            {
                path.push_back(s.substr(index, i - index + 1));
                backtrack(s, i+1);
                path.pop_back();
            }
            else
            {
                continue;
            }
        }
    }

    bool isPalindrome(const string& s, int left, int right)
    {
        for(int i = left, j = right; i<=j; i++, j--)
        {
            if(s[i] != s[j])
            {
                return false;
            }
        }
        return true;
    }
};

int main()
{

}
