#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string path;
        backtrack(n, res, path, 0, 0);
        return res;
    }

    void backtrack(int n, vector<string>& res, string& path, int left, int right)
    {
        if(path.size() == 2*n)
        {
            res.push_back(path);
            return;
        }

        if(left < n)
        {
            path.push_back('(');
            backtrack(n, res, path, left+1, right);
            path.pop_back();
        }

        if(left > right)
        {
            path.push_back(')');
            backtrack(n, res, path, left, right + 1);
            path.pop_back();
        }
    } 
};

int main()
{
    
}

