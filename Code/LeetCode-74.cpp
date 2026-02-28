#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int r = matrix.size();
        int c = matrix[0].size();

        int left = 0;
        int right = r*c - 1;

        while(left<=right)
        {
            int mid = left + (right - left) / 2;

            int val = matrix[mid / c][mid % c];

            if(val == target)
            {
                return true;
            }
            else if(val > target)
            {
                right = mid - 1;
            }
            else
            {
                left = mid + 1;
            }
        }
        return false;
    }
};

int main()
{
    
}

