#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});
        
        vector<vector<int>> result;
        
        result.push_back(vector<int>{intervals[0][0], intervals[0][1]});

        for(int i = 0; i<intervals.size(); i++)
        {
            if(intervals[i][0] <= result.back()[1])
            {
                result.back()[1] = max(intervals[i][1], result.back()[1]); 
            }
            else
            {
                result.push_back(vector<int>{intervals[i][0], intervals[i][1]});
            }
        }

        return result;
    }
};

// class Solution {
// public:
//     vector<vector<int>> merge(vector<vector<int>>& intervals) {
//         sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b){return a[0] < b[0];});
        
//         vector<vector<int>> result;

//         int left = intervals[0][0];
//         int right = intervals[0][1];
        
//         for(int i = 1; i<intervals.size(); i++)
//         {
//             if(intervals[i][0] <= right)
//             {
//                 right = max(right, intervals[i][1]);
//             }
//             else
//             {
//                 result.push_back(vector<int>{left, right});
//                 left = intervals[i][0];
//                 right = intervals[i][1];
//             }
//         }
        
//         result.push_back(vector<int>{left, right});

//         return result;
//     }
// };



int main()
{

}
