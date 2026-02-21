#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        sort(candidates.begin(), candidates.end());

        backtrack(candidates, target, res, path, 0);

        return res;
    }

    void backtrack(const vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& path, int index)
    {
        if(target == 0)
        {
            res.push_back(path);
            return;
        }

        for(int i = index; i<candidates.size(); i++)
        {
            if(target - candidates[i] < 0)
            {
                break;
            }

            path.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], res, path, i);
            path.pop_back();
        }
    }
};

int main()
{
    
}

