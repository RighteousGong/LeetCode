/*
115. 不同的子序列
困难

给你两个字符串 s 和 t ，统计并返回在 s 的 子序列 中 t 出现的个数。
测试用例保证结果在 32 位有符号整数范围内。

示例 1：
输入：s = "rabbbit", t = "rabbit"
输出：3
解释：
如下所示, 有 3 种可以从 s 中得到 "rabbit" 的方案。
'rabb'b'it'
'ra'b'bbit'
'rab'b'bit'

示例 2：
输入：s = "babgbag", t = "bag"
输出：5
解释：
如下所示, 有 5 种可以从 s 中得到 "bag" 的方案。 
'ba'b'g'bag
'ba'bgba'g'
'b'abgb'ag'
ba'b'gb'ag'
babg'bag'

提示：
1 <= s.length, t.length <= 1000
s 和 t 由英文字母组成
*/
#include <string>
#include <vector>

class Solution
{
public:
    int numDistinct(std::string s, std::string t)
    {
        std::vector<std::vector<uint64_t>> dp(t.size()+1, std::vector<uint64_t> (s.size()+1, 0)); // dp[i][j]：以i-1为结尾的s子序列中出现以j-1为结尾的t的个数为dp[i][j]。
        for (int j = 0; j <= s.size(); ++ j) dp[0][j] = 1;
        for (int i = 1; i <= t.size(); ++ i)
        {
            for (int j = 1; j <= s.size(); ++ j)
            {
                if (t[i-1] == s[j-1])
                    dp[i][j] = dp[i-1][j-1] + dp[i][j-1];
                else
                    dp[i][j] = dp[i][j-1];
            }
        }
        return dp.back().back();
    }
};

class Solution
{
public:
    int numDistinct(std::string s, std::string t)
    {
        std::vector<uint64_t> dp(s.size()+1, 1); // dp[i][j]：以i-1为结尾的s子序列中出现以j-1为结尾的t的个数为dp[i][j]。
        dp[0] = 0;
        for (int i = 1; i <= t.size(); ++ i)
        {
            uint64_t res = i == 1 ? 1 : 0; // 弥补第一次dp[0] = 1;
            for (int j = 1; j <= s.size(); ++ j)
            {
                if (t[i-1] == s[j-1])
                {
                    uint64_t tmp = dp[j];
                    dp[j] = dp[j-1] + res;
                    res = tmp;
                }
                else
                {
                    res = dp[j];
                    dp[j] = dp[j-1];
                }
            }
        }
        return dp.back();
    }
};