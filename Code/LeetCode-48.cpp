#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int left = 0;
        int right = matrix.size() - 1;
        int top , bottom;
        while(left<=right)
        {   
            for(int i = 0; i<right - left; i++)
            {
                top = left;
                bottom = right;
                
                int topleft = matrix[top][left + i];
                matrix[top][left + i] = matrix[bottom - i][left];
                matrix[bottom - i][left] = matrix[bottom][right - i];
                matrix[bottom][right - i] = matrix[top + i][right];
                matrix[top + i][right] = topleft;
            }
            left++;
            right--;
        }
    }
};

int main()
{
    
}
