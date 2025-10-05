#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int result = 0;
        int index = s.size() - 1;

        for(int i = g.size() - 1; i>=0; i--)
        {
            if(index >= 0 && s[index] >= g[i])
            {
                result++;
                index--;
            }
        }
        return result;
    }
};

int main()
{
}
