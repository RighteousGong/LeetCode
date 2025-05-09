/*
123. 买卖股票的最佳时机 III
困难

给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

示例 1:
输入：prices = [3,3,5,0,0,3,1,4]
输出：6
解释：在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
     随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。

示例 2：
输入：prices = [1,2,3,4,5]
输出：4
解释：在第 1 天（股票价格 = 1）的时候买入，在第 5 天 （股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。   
     注意你不能在第 1 天和第 2 天接连购买股票，之后再将它们卖出。   
     因为这样属于同时参与了多笔交易，你必须在再次购买前出售掉之前的股票。

示例 3：
输入：prices = [7,6,4,3,1] 
输出：0 
解释：在这个情况下, 没有交易完成, 所以最大利润为 0。

示例 4：
输入：prices = [1]
输出：0
 

提示：
1 <= prices.length <= 105
0 <= prices[i] <= 105
*/
#include <vector>

class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        /*
        一天一共就有五个状态，
        没有操作 （其实我们也可以不设置这个状态）
        第一次持有股票
        第一次不持有股票
        第二次持有股票
        第二次不持有股票
        */
        std::vector<std::vector<int>> dp(prices.size(), std::vector<int>(5, 0));
        dp[0][0] = 0; // 没有操作
        dp[0][1] = -prices[0]; // 第一次持有股票
        dp[0][2] = 0; // 第一次不持有股票
        dp[0][3] = -prices[0]; // 第二次持有股票
        dp[0][4] = 0; // 第二次不持有股票

        for (int i = 1; i < prices.size(); ++ i)
        {
            dp[i][0] = std::max(std::max(dp[i-1][0], dp[i-1][2]), dp[i-1][4]);
            dp[i][1] = std::max(dp[i-1][1], -prices[i]);
            dp[i][2] = std::max(dp[i-1][2], dp[i-1][1]+prices[i]);
            dp[i][3] = std::max(dp[i-1][3], dp[i-1][2]-prices[i]);
            dp[i][4] = std::max(dp[i-1][4], dp[i-1][3]+prices[i]);
        }
        int result = std::max(std::max(dp[prices.size()-1][4], dp[prices.size()-1][2]), dp[prices.size()-1][0]);
        return result;
    }
};

class Solution
{
public:
    int maxProfit(std::vector<int>& prices)
    {
        /*
        一天一共就有五个状态，
        没有操作 （其实我们也可以不设置这个状态）
        第一次持有股票
        第一次不持有股票
        第二次持有股票
        第二次不持有股票
        */
        std::vector<std::vector<int>> dp(2, std::vector<int>(4, 0));
        dp[0][0] = -prices[0]; // 第一次持有股票
        dp[0][2] = -prices[0]; // 第二次持有股票

        for (int i = 1; i < prices.size(); ++ i)
        {
            dp[i%2][0] = std::max(dp[(i-1)%2][0], -prices[i]);
            dp[i%2][1] = std::max(dp[(i-1)%2][1], dp[(i-1)%2][0]+prices[i]);
            dp[i%2][2] = std::max(dp[(i-1)%2][2], dp[(i-1)%2][1]-prices[i]);
            dp[i%2][3] = std::max(dp[(i-1)%2][3], dp[(i-1)%2][2]+prices[i]);
        }

        return dp[(prices.size()-1)%2][3];
    }
};