/*
买卖股票的最佳时机 II

给你一个整数数组 prices ，其中 prices[i] 表示某支股票第 i 天的价格。
在每一天，你可以决定是否购买和/或出售股票。你在任何时候 最多 只能持有 一股 股票。你也可以先购买，然后在 同一天 出售。
返回 你能获得的 最大 利润 。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/top-interview-questions-easy/x2zsx1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include<iostream>
#include<vector>

int maxProfit(std::vector<int>& prices);

int main(){
    std::vector<int> nums = {7,1,5,3,6,4};
    int sum = maxProfit(nums);
    std::cout << sum << std::endl;
}

int maxProfit(std::vector<int>& prices) {
    auto buy = prices.begin();
    auto sell = buy;
    auto end = prices.end();
    int sum = 0;
    while(sell < end){
        if(*sell > *buy){
            sum += (*sell - *buy);
        }
        buy = sell;
        sell++;
    }
    return sum;
}