#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> nums;

    void backTracking(int n, int k, int index)
    {
        if(nums.size() == k)
        {
            result.push_back(nums);
            return;
        }

        for(int i = index; i <= n - (k - nums.size()) + 1; i++)
        {
            nums.push_back(i);
            backTracking(n, k, i + 1);
            nums.pop_back();
        }  
    }


    vector<vector<int>> combine(int n, int k) {
        backTracking(n, k, 1);
        return result;
    }
};

int main()
{
    
}
