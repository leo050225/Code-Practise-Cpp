#include<iostream>
using namespace std;
#include<vector>

class Solution {
public:
    bool BackTraking(vector<vector<char>>& borad)
    {
        for(int i = 0; i < borad.size(); i++)
        {
            for(int j = 0; j < borad[0].size(); j++)
            {
                if(borad[i][j] == '.')
                {
                    for(int k = '1'; k <= '9'; k++)
                    {
                        if(isValid(i, j, k, borad))
                        {
                            borad[i][j] = k;
                            if(BackTraking(borad))return true;
                            borad[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }

    bool isValid(int row, int col, char val, vector<vector<char>>& borad)
    {
        for(int i = 0; i<9; i++)
        {
            if(borad[row][i] == val)
            {
                return false;
            }
        }

        for(int i = 0; i<9; i++)
        {
            if(borad[i][col] == val)
            {
                return false;
            }
        }

        int startRow = (row/3)*3;
        int startCol = (col/3)*3;

        for(int i = startRow; i<startRow + 3; i++)
        {
            for(int j = startCol; j<startCol + 3; j++)
            {
                if(borad[i][j] == val)
                {
                    return false;
                }
            }
        }
        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        BackTraking(board);
        return;
    }
};

int main()
{
}
