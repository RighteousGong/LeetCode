/*
279. 完全平方数

中等
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

示例 1：
输入：n = 12
输出：3 
解释：12 = 4 + 4 + 4

示例 2：
输入：n = 13
输出：2
解释：13 = 4 + 9
 
提示：
1 <= n <= 104
*/
#include <vector>

class Solution 
{
public:
    int numSquares(int n) // 二维
    {
        int base = 1;
        std::vector<int> squares;
        while (base*base <= n)
        {
            squares.emplace_back(base*base);
            ++base;
        }

        std::vector<std::vector<int>> dp(squares.size(), std::vector<int>(n+1, n));
        for (int i = 0; i < squares.size(); ++i)
            dp[i][0] = 0;
        for (int i = 1; i <= n; ++i)
            if (i % squares[0] == 0) dp[0][i] = i/squares[0];


        for (int i = 1; i < squares.size(); ++i)
        {
            for (int j = 0; j <= n; ++j)
            {
                if (j < squares[i]) dp[i][j] = dp[i-1][j];
                else
                {
                    dp[i][j] = std::min(dp[i-1][j], dp[i][j - squares[i]] + 1);
                }
            }
        }
        return dp.back()[n];
    }

    int numSquares(int n) // 一维
    {
        int base = 1;
        std::vector<int> squares;
        while (base*base <= n)
        {
            squares.emplace_back(base*base);
            ++base;
        }

        std::vector<int> dp(n+1, n);
        dp[0] = 0;

        for (int i = 0; i < squares.size(); ++i)
        {
            for (int j = squares[i]; j <= n; ++j)
            {
                dp[j] = std::min(dp[j], dp[j - squares[i]] + 1);
            }
        }
        return dp[n];
    }

    int numSquares(int n) // 一维
    {
        std::vector<int> dp(n+1, n);
        dp[0] = 0;

        for (int i = 1; i * i<= n; ++i)
        {
            for (int j = i; j*j <= n; ++j)
            {
                dp[j] = std::min(dp[j], dp[j - i*i] + 1);
            }
        }
        return dp[n];
    }
};