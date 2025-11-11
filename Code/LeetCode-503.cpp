#include <iostream>
using namespace std;
#include <vector>
#include <map>
#include <stack>

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> result(nums.size(), -1);
        stack<int> st;

        if(nums.size() == 0)return result;

        for(int i = 0; i<nums.size() * 2; i++)
        {
            while ((!st.empty() && nums[i % nums.size()] > nums[st.top()]))
            {
                result[st.top()] = nums[i % nums.size()];
                st.pop();
            }
            st.push(i % nums.size());
        }

        return result;
    }
};

int main()
{

}
