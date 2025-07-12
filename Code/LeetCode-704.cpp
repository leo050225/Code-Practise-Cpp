#include <iostream>
using namespace std;
#include<algorithm>
#include<vector>

class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int n = 0;
        for(vector<int> :: iterator it = nums.begin();it!=nums.end();it++)
        {
            if(*it==target)return n;
            n++;
        }
        return -1;
    }
};
