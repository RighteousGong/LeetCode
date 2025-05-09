/*
121. 买卖股票的最佳时机
简单

给定一个数组 prices ，它的第 i 个元素 prices[i] 表示一支给定股票第 i 天的价格。
你只能选择 某一天 买入这只股票，并选择在 未来的某一个不同的日子 卖出该股票。设计一个算法来计算你所能获取的最大利润。
返回你可以从这笔交易中获取的最大利润。如果你不能获取任何利润，返回 0 。

示例 1：
输入：[7,1,5,3,6,4]
输出：5
解释：在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。

示例 2：
输入：prices = [7,6,4,3,1]
输出：0
解释：在这种情况下, 没有交易完成, 所以最大利润为 0。

提示：
1 <= prices.length <= 105
0 <= prices[i] <= 104
*/
#include <vector>

// 暴力解法
class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        std::vector<int> dp(prices.size(), 0);

        for (int i = 1; i < dp.size(); ++ i)
        {
            for (int j = 0; j < i; ++ j)
            {
                dp[i] = std::max(dp[i-1], std::max(dp[i], prices[i] - prices[j]));
            }
        }

        return dp.back();
    }
};

// 动态规划
class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(2, 0)); // dp[i][0] 表示第i天持有股票所得最多现金 dp[i][1] 表示第i天不持有股票所得最多现金
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < dp.size(); ++ i)
        {
            dp[i][0] = std::max(dp[i-1][0], -prices[i]);
            dp[i][1] = std::max(dp[i-1][1], dp[i - 1][0]+prices[i]);
        }

        return dp.back()[1];
    }
};

// 动态规划 更快
class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        std::vector<std::vector<int>> dp(2, std::vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < prices.size(); ++ i)
        {
            dp[i%2][0] = std::max(dp[(i-1)%2][0], -prices[i]);
            dp[i%2][1] = std::max(dp[(i-1)%2][1], dp[(i-1)%2][0]+prices[i]);
        }

        return dp[(prices.size()-1)%2][1]; // prices len:3->dp[0][1] -> dp[(3-1)%2][1] ->dp[0][1]
    }
};