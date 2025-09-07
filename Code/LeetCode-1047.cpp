#include<iostream>
using namespace std;
#include<stack>


class Solution {
public:
    string removeDuplicates(string s) {
        string result;

        for(char c : s)
        {
            if(result.empty() || result.back() != c)
                result.push_back(c);
            else //if(result.back() == c)
                result.pop_back();
        }
        return result;
    }
};

int main()
{

} 
