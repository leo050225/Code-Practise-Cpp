#include<iostream>
using namespace std;
#include<vector>
#include<unordered_map>

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> num_map;//<數值(key),下標(value)>
        
        for(int i = 0; i<nums.size(); i++)
        {
            auto iter = num_map.find(target - nums[i]);

            if(iter!=num_map.end())
            {
                return {iter->second,i};
            }
            else
            {
                num_map.insert(pair<int,int>{nums[i],i});
            }
        }
        return{};
    }
};

int main()
{
    return 0;
}
