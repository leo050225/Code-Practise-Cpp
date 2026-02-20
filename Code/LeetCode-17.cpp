#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    const vector<string> mapping = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> letterCombinations(string digits) {
        if(digits == "")
        {
            return {};
        }

        vector<string> res;
        string path;
        backtrack(digits, 0, res, path);
        return res;
    }

    void backtrack(const string& digits, int index, vector<string>& res, string& path)
    {
        if(index >= digits.size())
        {
            res.push_back(path);
            return;
        }

        const string& letters = mapping[digits[index] - '0'];

        for(char c : letters)
        {
            path.push_back(c);
            backtrack(digits, index+1, res, path);
            path.pop_back();
        }
    }
};

int main()
{
    
}

