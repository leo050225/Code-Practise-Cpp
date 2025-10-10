#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size() == 0)return 0;

        sort(intervals.begin(), intervals.end(), [](vector<int>a, vector<int> b){return a[0] < b[0];});

        int result = 0;

        for(int i = 1; i<intervals.size(); i++)
        {
            if(intervals[i - 1][1] > intervals[i][0])
            {
                result++;
                intervals[i][1] = min(intervals[i - 1][1], intervals[i][1]);
            }
        }

        return result;
    }
};

int main()
{

}
