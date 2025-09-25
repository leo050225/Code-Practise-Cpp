#include <iostream>
using namespace std;
#include<vector>

class Solution {
public:
    const string letterMap[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> result;//結果

    string str;//紀錄


    void backTracking(string digits, int index)
    {
        if(digits.length() == index)
        {
            result.push_back(str);
            return;
        }

        int digit = digits[index] - '0';
        string letter = letterMap[digit];

        for(int i = 0; i < letter.size(); i++)
        {
            str.push_back(letter[i]);
            backTracking(digits, index + 1);
            str.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if(digits.empty())return result;
        backTracking(digits, 0);
        return result;
    }
};

int main()
{
    
}
