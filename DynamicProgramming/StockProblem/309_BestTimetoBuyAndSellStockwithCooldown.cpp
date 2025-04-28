/*
309. 买卖股票的最佳时机含冷冻期
中等

给定一个整数数组prices，其中第  prices[i] 表示第 i 天的股票价格 。​
设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:
输入: prices = [1,2,3,0,2]
输出: 3 
解释: 对应的交易状态为: [买入, 卖出, 冷冻期, 买入, 卖出]

示例 2:
输入: prices = [1]
输出: 0
 
提示：
1 <= prices.length <= 5000
0 <= prices[i] <= 1000
*/
#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        /*
        四个状态：
        持有股票状态
        保持卖出股票状态
        今天卖出股票
        今天为冷冻期状态
        */
        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(4, 0));
        dp[0][0] = -prices[0];

        for (int i = 1; i < prices.size(); ++ i)
        {
            dp[i][0] = std::max(std::max(dp[i-1][0], dp[i-1][3]-prices[i]), dp[i-1][1]-prices[i]);
            dp[i][1] = std::max(dp[i-1][1], dp[i-1][3]);
            dp[i][2] = dp[i-1][0] + prices[i];
            dp[i][3] = dp[i-1][2];
        }

        return std::max(dp[prices.size() - 1][1], std::max(dp[prices.size() - 1][2], dp[prices.size() - 1][3]));
    }
};

class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        /*
        四个状态：
        持有股票状态
        保持卖出股票状态
        今天卖出股票
        今天为冷冻期状态
        */
        std::vector<std::vector<int>> dp(2, std::vector<int>(4, 0));
        dp[0][0] = -prices[0];

        for (int i = 1; i < prices.size(); ++ i)
        {
            dp[i%2][0] = std::max(std::max(dp[(i-1)%2][0], dp[(i-1)%2][3]-prices[i]), dp[(i-1)%2][1]-prices[i]);
            dp[i%2][1] = std::max(dp[(i-1)%2][1], dp[(i-1)%2][3]);
            dp[i%2][2] = dp[(i-1)%2][0] + prices[i];
            dp[i%2][3] = dp[(i-1)%2][2];
        }

        return std::max(dp[(prices.size() - 1)%2][1], std::max(dp[(prices.size() - 1)%2][2], dp[(prices.size() - 1)%2][3]));
    }
};