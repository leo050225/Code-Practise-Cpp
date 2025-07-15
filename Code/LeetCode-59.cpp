#include <iostream>
using namespace std;
#include<algorithm>
#include<vector>

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) 
    {
        vector<vector<int>> vv(n,vector<int>(n));
        
        int num = 1;

        int left = 0;
        int right = n-1;

        int top = 0;
        int bottom = n-1;
        
        while (left<=right && top<=bottom)
        {
            for(int n1 = left; n1 <= right; n1++)
            {
                vv[top][n1] = num;
                num++;
            }

            for(int n2 = top + 1; n2 <= bottom; n2++)
            {
                vv[n2][right] = num;
                num++;
            }
            
            //避免n是奇數 是奇數就把往回推的跳過
            if(left < right && top < bottom)
            {
                for(int n3 = right - 1; n3 >left; n3--)
                {
                    vv[bottom][n3] = num;
                    num++;
                }

                for(int n4 = bottom; n4 >top; n4--)
                {
                    vv[n4][left] = num;
                    num++;
                }
            }

            left++;
            right--;
            top++;
            bottom--;
        }
        return  vv;
    }
};

int main()
{
    Solution s;
    int num = 3;
    vector<vector<int>> vv = s.generateMatrix(num);

    for(int i = 0; i < num; i++)
    {
        for(int j = 0; j<num; j++)
        {
            cout<<vv[i][j];
        }
        cout<<endl;
    }
}
