#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int jump(vector<int>& nums) {
        int result = 0;
        int cur = 0;
        int next = 0;

        for(int i = 0; i < nums.size() - 1; i++)
        {
            next = max(next, i + nums[i]);

            if(i == cur)
            {
                cur = next;
                result++;
            }
        }
        return result;
    }
};

int main()
{
    
}
