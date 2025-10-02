#include <iostream>
using namespace std;
#include<vector>

class Solution {
public:

    vector<vector<string>> result;

    void BackTracking(int n, int row, vector<string>& chessborad)
    {
        if(row == n)
        {
            result.push_back(chessborad);
            return;
        }

        for(int col = 0; col < n; col++)
        {
            if(isValid(row, col, chessborad, n))
            {
                chessborad[row][col] = 'Q';
                BackTracking(n, row + 1, chessborad);
                chessborad[row][col] = '.';
            }
        }
    }

    bool isValid(int row, int col, vector<string>& chessborad, int n)
    {
        //正上方
        for(int i = 0; i < n; i++)
        {
            if(chessborad[i][col] == 'Q')
            {
                return false;
            }
        }

        //左上斜線
        for(int i = row - 1, j = col - 1; i>=0 && j>=0; i--, j--)
        {
            if(chessborad[i][j] == 'Q')
            {
                return false;
            }
        }

        //右上斜線
        for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++)
        {
            if(chessborad[i][j] == 'Q')
            {
                return false;
            }
        }

        return true;
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> chessborad(n,string(n, '.'));
        BackTracking(n, 0, chessborad);
        return result;
    }
};

int main()
{
    
}
