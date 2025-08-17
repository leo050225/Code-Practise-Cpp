#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>

void getNext(vector<int> &next, const string& s) {
    int j = 0;
    next[0] = 0;

    for(int i = 1; i<s.size(); i++)
    {
        while(j > 0 && s[i] != s[j])
        {
            j = next[j-1];
        }

        if(s[i] == s[j]) j++;

        next[i] = j;
    }
}

class Solution {
public:
    int strStr(string haystack, string needle) {
        
        //needle為空字串
        if(needle.size() == 0)return 0;

        vector<int> next(needle.size());

        //算出前綴表
        getNext(next, needle);
        int j = 0;

        for(int i = 0; i < haystack.size(); i++)
        {
            //如果匹配到不一樣 根據前傳表找到 最常相等前後綴表的 前最表後一位 (EX:aabaaf的b)
            while (j > 0 && haystack[i] != needle[j])
            {
                j = next[j-1];
            }
            
            //如果一樣兩個都會進位
            if(haystack[i] == needle[j]) j++;
            
            //如果j到了needle的尾部 找出匹配的第一個下標
            if(j == needle.size())
                return (i - needle.size() + 1);
            
        }
        //甚麼都沒有返回-1
        return -1;
    }
};

int main()
{

}
