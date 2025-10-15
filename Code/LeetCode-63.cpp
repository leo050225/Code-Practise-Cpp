#include <iostream>
using namespace std;
#include<vector>

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {

        if(obstacleGrid[0][0] == 1) return 0;

        vector<int> dp(obstacleGrid[0].size(), 0);

        for(int i = 0; i<obstacleGrid[0].size(); i++)
        {
            if(obstacleGrid[0][i] == 1)
                dp[i] = 0;
            else if(i == 0)
                dp[i] = 1;
            else
                dp[i] = dp[i - 1];
        }

        for(int i = 1; i<obstacleGrid.size(); i++)
        {
            for(int j = 0; j<obstacleGrid[0].size(); j++)
            {
                if(obstacleGrid[i][j] == 1)
                    dp[j] = 0;
                else if(j != 0)
                    dp[j] = dp[j] + dp[j - 1]; 
                    
            }
        }

        return dp[dp.size() - 1];
    }
};

int main()
{
    
}
