#pragma once

#include <iostream>
#include <vector>
#include <unordered_set>

class CSolution 
{
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board)
    {
        bool arrRow[9][9] = { false }, arrLine[9][9] = { false }, arrSudoku[9][9] = { false };
        for (int row = 0; row < 9; row++)
        {
            for (int line = 0; line < 9; line++)
            {
                const char& data = board[row][line];
                if (data != '.')
                {
                    const int& num = data - '0' - 1, & indexSudoku = row / 3 * 3 + line / 3;
                    if (arrRow[row][num] || arrLine[line][num] || arrSudoku[indexSudoku][num])
                        return false;

                    arrRow[row][num] = arrLine[line][num] = arrSudoku[indexSudoku][num] = true;
                }
            }
        }
        return true;
    }
};
