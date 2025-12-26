#include <iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0] = 1;

        int result = 0;
        int pre = 0;

        for(int i = 0; i<nums.size(); i++)
        {
            pre += nums[i];

            if(m.find(pre - k) != m.end())
            {
                result += m[pre - k];
            }
            m[pre]++;
        }

        return result;
    }
};

int main()
{
    
}
