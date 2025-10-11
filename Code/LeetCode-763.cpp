#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<unordered_map>

class Solution {
public:
    int hash[27] = {0};

    vector<int> partitionLabels(string s) {
        vector<int> result;
        
        for(int i = 0; i<s.size(); i++)
        {
            hash[s[i] - 'a'] = i;
        }

        int left = 0, right = 0;

        for(int i = 0; i<s.size(); i++)
        {
            right = max(right, hash[s[i] - 'a']);

            if(i == right)
            {
                result.push_back(right - left + 1);
                left = i + 1;
            }
        }

        return result;
    }
};

int main()
{

}
