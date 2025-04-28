/*
516. 最长回文子序列
中等

给你一个字符串 s ，找出其中最长的回文子序列，并返回该序列的长度。

子序列定义为：不改变剩余字符顺序的情况下，删除某些字符或者不删除任何字符形成的一个序列。 

示例 1：
输入：s = "bbbab"
输出：4
解释：一个可能的最长回文子序列为 "bbbb" 。

示例 2：
输入：s = "cbbd"
输出：2
解释：一个可能的最长回文子序列为 "bb" 。

提示：
1 <= s.length <= 1000
s 仅由小写英文字母组成
*/

#include <string>
#include <vector>

class Solution
{
public:
    int longestPalindromeSubseq(std::string s)
    {
        std::vector<std::vector<int>> dp(s.size(), std::vector(s.size(), 0));
        for (int i = 0; i < s.size(); i++) dp[i][i] = 1;
        for (int i = s.size() - 2; i >= 0; -- i)
        {
            for (int j = i+1; j < s.size(); ++ j)
            {
                if (s[i] == s[j])
                {
                    dp[i][j] = dp[i+1][j-1]+2;
                }
                else
                {
                    dp[i][j] = std::max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        return dp[0].back();
    }
};

class Solution
{
public:
    int longestPalindromeSubseq(std::string s)
    {
        std::vector<int> dp(std::vector(s.size(), 1));
        for (int i = s.size() - 2; i >= 0; -- i)
        {
            int res = 0;
            int tmp = dp[i];
            for (int j = i+1; j < s.size(); ++ j)
            {
                tmp = dp[j];
                if (s[i] == s[j])
                    dp[j] = res +2;
                else
                    dp[j] = std::max(dp[j], dp[j-1]);
                res = tmp;
            }
        }
        return dp.back();
    }
};