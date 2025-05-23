/*
322. 零钱兑换
中等

给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。
计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。
你可以认为每种硬币的数量是无限的。

示例 1：
输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1

示例 2：
输入：coins = [2], amount = 3
输出：-1

示例 3：
输入：coins = [1], amount = 0
输出：0
 
提示：
1 <= coins.length <= 12
1 <= coins[i] <= 231 - 1
0 <= amount <= 104
*/
#include <vector>
#include <algorithm>
#include <iostream>

class Solution
{
public:
    int coinChange(std::vector<int>& coins, int amount) // 二维
    {
        std::vector<std::vector<uint64_t>> dp(coins.size(), std::vector<uint64_t> (amount+1, 2147483647));
        for (int i = 0; i < coins.size(); ++i)
            dp[i][0] = 0;
        for (int i = 1; i <= amount; ++i)
            if (i % coins[0] == 0) dp[0][i] = i/coins[0];

        for (int i = 1; i < coins.size(); ++i)
        {
            for (int j = 0; j <= amount; ++j)
            {
                if (j < coins[i]) dp[i][j] = dp[i-1][j];
                else
                {
                    dp[i][j] = std::min(dp[i-1][j], dp[i][j-coins[i]] +1);
                }
            }
        }
        return dp[coins.size()-1][amount] == 2147483647 ? -1: dp[coins.size()-1][amount];
    }

    int coinChange(std::vector<int>& coins, int amount) // 一维
    {
        std::vector<uint64_t> dp(amount+1, 2147483647); // uint64_t.max=18446744073709551615
        dp[0] = 0;

        for (int i = 0; i < coins.size(); ++i)
        {
            for (int j = coins[i]; j <= amount; ++j)
                dp[j] = std::min(dp[j], dp[j-coins[i]] +1); // 如果数组是int，这需要做判断
        }
        return dp[amount] == 2147483647 ? -1: dp[amount];
    }
};