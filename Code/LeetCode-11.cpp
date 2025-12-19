#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int leftIndex = 0;
        int rightIndex = height.size() - 1;
        
        int maxSum = 0;
        
        int h = 0;

        while(leftIndex < rightIndex)
        {
            h = min(height[leftIndex], height[rightIndex]);

            maxSum = max(maxSum, h * (rightIndex - leftIndex));

            if(height[leftIndex] > height[rightIndex])
            {
                rightIndex--;
            }
            else
            {
                leftIndex++;
            }
        }

        return maxSum;
    }
};

int main()
{

}
