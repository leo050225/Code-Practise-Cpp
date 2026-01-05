#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int left = 0;
        int top = 0;
        int right = matrix[0].size() - 1;
        int bottom = matrix.size() - 1;

        while(left<=right && top<=bottom)
        {
            for(int i = top; i <= right; i++)
                result.push_back(matrix[top][i]);
        
            for(int i = top + 1; i<=bottom; i++)
                result.push_back(matrix[i][right]);

            if(left < right && top < bottom)
            {
                for(int i = right - 1; i>left; i--)
                    result.push_back(matrix[bottom][i]);
    
                for(int i = bottom; i>top; i--)
                    result.push_back(matrix[i][left]);
            }
            left++;
            top++;
            right--;
            bottom--;
        } 
        return result;
    }
};

int main()
{
    
}
