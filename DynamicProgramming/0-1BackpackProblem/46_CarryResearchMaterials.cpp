/*
46. 携带研究材料 (此题是卡码网上的题，不是LeetCode)
题目描述
小明是一位科学家，他需要参加一场重要的国际科学大会，以展示自己的最新研究成果。他需要带一些研究材料，但是他的行李箱空间有限。这些研究材料包括实验设备、文献资料和实验样本等等，它们各自占据不同的空间，并且具有不同的价值。 

小明的行李空间为 N，问小明应该如何抉择，才能携带最大价值的研究材料，每种研究材料只能选择一次，并且只有选与不选两种选择，不能进行切割。

输入描述
第一行包含两个正整数，第一个整数 M 代表研究材料的种类，第二个正整数 N，代表小明的行李空间。

第二行包含 M 个正整数，代表每种研究材料的所占空间。 

第三行包含 M 个正整数，代表每种研究材料的价值。

输出描述
输出一个整数，代表小明能够携带的研究材料的最大价值。
输入示例
6 1
2 2 3 1 5 2
2 3 1 5 4 3
输出示例
5
提示信息
小明能够携带 6 种研究材料，但是行李空间只有 1，而占用空间为 1 的研究材料价值为 5，所以最终答案输出 5。 

数据范围：
1 <= N <= 5000
1 <= M <= 5000
研究材料占用空间和价值都小于等于 1000

题目链接：https://kamacoder.com/problempage.php?pid=1046
*/
#include <iostream>
#include <vector>

int main()
{
    int n, weight;
    std::cin >> n >> weight;

    std::vector<int> weights(n, 0);
    std::vector<int> values(n, 0);

    for (int i = 0; i < n; ++i)
        std::cin >> weights[i];
    for (int i = 0; i < n; ++i)
        std::cin >> values[i];
    
    std::vector<std::vector<int>> dp(n, std::vector<int> (weight+1, 0));
    for (int i = weights[0]; i <= weight; ++ i)
        dp[0][i] = values[0];

    for (int i = 1; i < weights.size(); ++ i)
    {
        for (int j = 0; j <= weight; ++ j)
        {
            if (j < weights[i]) dp[i][j] = dp[i - 1][j];
            else
            {
                dp[i][j] = std::max(dp[i-1][j], dp[i-1][j - weights[i]] + values[i]);
            }
        }
    }

    std::cout << dp[n - 1][weight] << std::endl;

    return 0;
}