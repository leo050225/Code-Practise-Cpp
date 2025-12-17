#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;

        for(string str : strs)
        {
            vector<int> count(26,0);
            for(char c : str)
            {
                count[c - 'a']++;
            }

            string text = "";

            for(int i = 0; i<count.size(); i++)
            {
                while(count[i] != 0)
                {
                    text += i + 'a';
                    count[i]--;
                }
            }

            m[text].push_back(str);
        }

        vector<vector<string>> v;
    
        for(auto &temp : m)
        {
            v.push_back(temp.second);
        }

        return v;
    }
};

int main()
{

}
