#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> result;
    vector<int> path;


    void backTracking(int target, int k, int sum, int index)
    {
        if(sum > target)return;

        if(path.size() == k)
        {   
            if(sum == target)result.push_back(path);
            return;
        }

        for(int i = index; i<= 9 - (k - path.size()) + 1; i++)
        {
            path.push_back(i);
            backTracking(target, k, sum + i, i + 1);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        backTracking(n, k, 0, 1);
        return result;
    }
};

int main()
{
    
}
