/*
51. N 皇后
困难

按照国际象棋的规则，皇后可以攻击与之处在同一行或同一列或同一斜线上的棋子。
n 皇后问题 研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
给你一个整数 n ，返回所有不同的 n 皇后问题 的解决方案。
每一种解法包含一个不同的 n 皇后问题 的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

示例 1：
输入：n = 4
输出：[[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
解释：如上图所示，4 皇后问题存在两个不同的解法。

示例 2：
输入：n = 1
输出：[["Q"]]

提示：
1 <= n <= 9
*/
#include <vector>
#include <string>

class Solution
{
    std::vector<std::vector<std::string>> result;
public:
    std::vector<std::vector<std::string>> solveNQueens(int n)
    {
        if (n >= 2 && n <= 3)
            return result;
        std::vector<std::string> tmp(1, "Q");
        if (n == 1)
        {
            result.emplace_back(std::vector<std::string>(1, "Q"));
            return  result;
        }
        std::string init(n, '.');
        std::vector<std::string> board(n, init);
        backTracking(board, 0, n);
        return result;
    }

    void backTracking(std::vector<std::string>& board, int row, int n)
    {
        if (n == row)
        {
            result.emplace_back(board);
            return;
        }
        for (int i = 0; i < n; ++i)
        {
            if (isValid(i, row, board))
            {
                board[row][i] = 'Q';
                backTracking(board, row + 1, n);
                board[row][i] = '.';
            }
        }
    }

    bool isValid(int col, int row, std::vector<std::string>& board)
    {
        for (int i = row - 1; i >= 0; -- i)
        {
            if (board[i][col] == 'Q')
                return false;
        }

        for (int i = col - 1, j = row - 1; i >= 0 && j >= 0; --i, --j)
        {
            if (board[j][i] == 'Q')
                return false;
        }

        for (int i = col + 1, j = row - 1; i < board.size() && j >= 0; ++i, --j)
        {
            if (board[j][i] == 'Q')
                return false;
        }
        return true;
    }
};