/*
37. 解数独
困难
编写一个程序，通过填充空格来解决数独问题。
数独的解法需 遵循如下规则：
数字 1-9 在每一行只能出现一次。
数字 1-9 在每一列只能出现一次。
数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。（请参考示例图）
数独部分空格内已填入了数字，空白格用 '.' 表示。

示例 1：
输入：board = [["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]
输出：[["5","3","4","6","7","8","9","1","2"],["6","7","2","1","9","5","3","4","8"],["1","9","8","3","4","2","5","6","7"],["8","5","9","7","6","1","4","2","3"],["4","2","6","8","5","3","7","9","1"],["7","1","3","9","2","4","8","5","6"],["9","6","1","5","3","7","2","8","4"],["2","8","7","4","1","9","6","3","5"],["3","4","5","2","8","6","1","7","9"]]
解释：输入的数独如上图所示，唯一有效的解决方案如下所示：
 
提示：
board.length == 9
board[i].length == 9
board[i][j] 是一位数字或者 '.'
题目数据 保证 输入数独仅有一个解
*/
#include <vector>

class Solution
{
public:
    void solveSudoku(std::vector<std::vector<char>>& board)
    {
        backTracking(board);
    }

    bool backTracking(std::vector<std::vector<char>>& board)
    {
        for (int row = 0; row < board.size(); ++ row)
        {
            for (int col = 0; col < board[0].size(); ++ col)
            {
                if (board[row][col] != '.')
                    continue;
                for (int it = 1; it <= 9; ++ it)
                {
                    if (isValid(col, row, it + '0', board))
                    {
                        board[row][col] = it + '0';
                        if (backTracking(board))
                            return true;
                        board[row][col] = '.';
                    }
                }
                return false;
            }
        }
        return true;
    }

    bool isValid(int col, int row, char it, std::vector<std::vector<char>>& board)
    {
        int colSize = board[0].size();
        for (int i = 0; i < colSize; ++i)
        {
            if (board[row][i] == it)
                return false;
        }
        int rowSize = board.size();
        for (int i = 0; i < rowSize; ++i)
        {
            if (board[i][col] == it)
                return false;
        }

        if (col <= 2)
            col = 2;
        else if (col <= 5)
            col = 5;
        else
            col = 8;

        if (row <= 2)
            row = 2;
        else if (row <= 5)
            row = 5;
        else
            row = 8;
        for (int i = row - 2; i <= row; ++ i)
        {
            for (int j = col - 2; j <= col; ++ j)
            {
                if (board[i][j] == it)
                    return false;
            }
        }
        return true;
    }
};