#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
    unordered_map<char, int> cnt;
    unordered_map<char, int> ori;

    bool check()
    {
        for(const auto &p : ori)
        {
            if(cnt[p.first] < p.second)
                return false;
            }
            return true;
    }

    string minWindow(string s, string t) {
        if(t.length() > s.length())
            return "";

        for(char c : t)
            ori[c]++;
        
        int left = 0;
        int right = 0;

        int len = INT_MAX;

        int ansL = -1;

        while(right < s.size())
        {
            if(ori.find(s[right]) != ori.end())
                cnt[s[right]]++;
            
            while(check() && left <= right)
            {
                if(right - left + 1 < len)
                {
                    len = right - left + 1;
                    ansL = left;
                }               
                
                if(ori.find(s[left]) != ori.end())
                    cnt[s[left]]--;

                left++;
            }
            right++;
        }

        return ansL == -1 ? string() : s.substr(ansL, len);
    }
};

int main()
{
    
}
