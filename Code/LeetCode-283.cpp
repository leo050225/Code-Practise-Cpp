#include<iostream>
#include<queue>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int index = 0;

        for(int i = 1; i<nums.size(); i++)
        {
            if(nums[i])
                swap(nums[index++], nums[i]);
        }
    }
};

int main()
{

}
