#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<vector<int>> dp(s.size() + 1, vector<int>(t.size() + 1, 0));

        int result = 0;

        for(int i = 1; i<=s.size(); i++)
        {
            for(int j = 1; j<=t.size(); j++)
            {
                if(s[i - 1] == t[j - 1])dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = dp[i][j - 1];
                result = max(result, dp[i][j]);
            }
        }

        return s.size() == result ? true : false;
    }
};

int main()
{
    
}
