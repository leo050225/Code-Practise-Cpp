#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<bool> isZeroX(matrix.size(),false);
        vector<bool> isZeroY(matrix[0].size(), false);

        for(int i = 0; i<matrix.size(); i++)
        {
            for(int j = 0; j<matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    isZeroX[i] = true;
                    isZeroY[j] = true;
                }
            }
        }

        for(int i = 0; i<matrix.size(); i++)
        {
            if(isZeroX[i])
            {
                fill(matrix[i].begin(), matrix[i].end(), 0);
                continue;
            }

            for(int j = 0; j<matrix[0].size(); j++)
            {
                if(isZeroY[j])
                {
                    matrix[i][j] = 0;
                }    
            }
        }

        return;
    }
};

int main()
{
    
}
