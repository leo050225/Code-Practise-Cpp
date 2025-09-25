#include <iostream>
using namespace std;
#include<vector>
#include<algorithm>

// a ^ a = 0
// a ^ 0 = a

class Solution {
public:
    int singleNumber(vector<int>& nums) {

        int res = 0;

        for(int i : nums)
        {
            res^=i;
        }

        return res;
    }
};

int main()
{
    
}
