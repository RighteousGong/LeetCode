/*
72. 编辑距离
中等
给你两个单词 word1 和 word2， 请返回将 word1 转换成 word2 所使用的最少操作数  。
你可以对一个单词进行如下三种操作：
插入一个字符
删除一个字符
替换一个字符

示例 1：
输入：word1 = "horse", word2 = "ros"
输出：3
解释：
horse -> rorse (将 'h' 替换为 'r')
rorse -> rose (删除 'r')
rose -> ros (删除 'e')

示例 2：
输入：word1 = "intention", word2 = "execution"
输出：5
解释：
intention -> inention (删除 't')
inention -> enention (将 'i' 替换为 'e')
enention -> exention (将 'n' 替换为 'x')
exention -> exection (将 'n' 替换为 'c')
exection -> execution (插入 'u')
 
提示：
0 <= word1.length, word2.length <= 500
word1 和 word2 由小写英文字母组成
*/
#include <string>
#include <vector>

class Solution
{
public:
    int minDistance(std::string word1, std::string word2)
    {
        std::vector<std::vector<int>> dp(word2.size()+1, std::vector(word1.size()+1, 1));
        for (int i = 0; i <= word2.size(); i++) dp[i][0] = i;
        for (int j = 0; j <= word1.size(); j++) dp[0][j] = j;
        for (int i = 1; i <= word2.size(); ++ i)
        {
            for (int j = 1; j <= word1.size(); ++ j)
            {
                if (word2[i-1] != word1[j-1])
                {
                    dp[i][j] = std::min(dp[i-1][j], std::min(dp[i][j-1], dp[i-1][j-1]))+1;
                }
                else
                {
                    dp[i][j] = dp[i-1][j-1]; // 相等时，删除的数量应为同时不加这两个数时删除的数量
                }
            }
        }
        return dp.back().back();
    }
};

class Solution
{
public:
    int minDistance(std::string word1, std::string word2)
    {
        std::vector<int> dp(word1.size()+1, 0);
        for (int j = 0; j <= word1.size(); j++) dp[j] = j;
        for (int i = 1; i <= word2.size(); ++ i)
        {
            dp[0] = i;
            int res = i-1; // 应对第一个元素相等的情况。
            for (int j = 1; j <= word1.size(); ++ j)
            {
                int tmp = dp[j];
                if (word2[i-1] != word1[j-1])
                {
                    dp[j] = std::min(dp[j], std::min(dp[j-1], res))+1;
                }
                else
                {
                    dp[j] = res;
                }
                res = tmp;
            }
        }
        return dp.back();
    }
};