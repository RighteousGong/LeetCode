/*
518. 零钱兑换 II
中等

给你一个整数数组 coins 表示不同面额的硬币，另给一个整数 amount 表示总金额。
请你计算并返回可以凑成总金额的硬币组合数。如果任何硬币组合都无法凑出总金额，返回 0 。
假设每一种面额的硬币有无限个。 
题目数据保证结果符合 32 位带符号整数。

示例 1：
输入：amount = 5, coins = [1, 2, 5]
输出：4
解释：有四种方式可以凑成总金额：
5=5
5=2+2+1
5=2+1+1+1
5=1+1+1+1+1

示例 2：
输入：amount = 3, coins = [2]
输出：0
解释：只用面额 2 的硬币不能凑成总金额 3 。

示例 3：
输入：amount = 10, coins = [10] 
输出：1

提示：
1 <= coins.length <= 300
1 <= coins[i] <= 5000
coins 中的所有值 互不相同
0 <= amount <= 5000
*/
#include <vector>

class Solution
{
public:
    int change(int amount, std::vector<int>& coins)
    {
        std::vector<std::vector<uint64_t>> dp(coins.size(), std::vector<uint64_t> (amount+1, 0)); // int不行

        for (int i = 0; i < coins.size(); ++ i)
            dp[i][0] = 1;
        for (int i = coins[0]; i <= amount; ++ i)
        {
            if (i%coins[0] == 0)
                dp[0][i] = 1;
        }

        for (int i = 1; i < coins.size(); ++i)
        {
            for (int j = 0; j <= amount; ++j)
            {
                if (coins[i] > j) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i][j - coins[i]] + dp[i-1][j];
            }
        }

        return dp[coins.size() - 1][amount];
    }

    int change(int amount, std::vector<int>& coins)
    {
        std::vector<uint64_t> dp(amount+1, 0); // int不行

        dp[0] = 1;
        for (int i = coins[0]; i <= amount; ++ i)
        {
            if (i%coins[0] == 0)
                dp[i] = 1;
        }

        for (int i = 1; i < coins.size(); ++i)
        {
            for (int j = coins[i]; j <= amount; ++j)
            {
                dp[j] += dp[j - coins[i]];
            }
        }

        return dp[amount];
    }
};