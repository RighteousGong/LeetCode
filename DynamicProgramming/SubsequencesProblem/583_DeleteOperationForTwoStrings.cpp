/*
583. 两个字符串的删除操作

给定两个单词 word1 和 word2 ，返回使得 word1 和  word2 相同所需的最小步数。

每步 可以删除任意一个字符串中的一个字符。

示例 1：
输入: word1 = "sea", word2 = "eat"
输出: 2
解释: 第一步将 "sea" 变为 "ea" ，第二步将 "eat "变为 "ea"

示例  2:
输入：word1 = "leetcode", word2 = "etco"
输出：4
 
提示：
1 <= word1.length, word2.length <= 500
word1 和 word2 只包含小写英文字母
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
                    dp[i][j] = std::min(dp[i-1][j], dp[i][j-1])+1;
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
                if (word2[i-1] != word1[j-1])
                {
                    res = dp[j];
                    dp[j] = std::min(dp[j], dp[j-1])+1;
                }
                else
                {
                    int tmp = dp[j];
                    dp[j] = res;
                    res = tmp;
                }
            }
        }
        return dp.back();
    }
};