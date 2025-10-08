#include <iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int cursum = 0;
    int totalsum = 0;
    int index = 0;

    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        for(int i = 0; i<gas.size(); i++)
        {
            cursum += (gas[i] - cost[i]);
            totalsum += (gas[i] - cost[i]);

            if(cursum < 0)
            {
                index = i + 1;
                cursum = 0;
            }
        }

        if(totalsum < 0) return -1;

        return index;
    }
};

int main()
{
    
}
