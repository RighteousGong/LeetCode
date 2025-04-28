/*
392. 判断子序列
简单

给定字符串 s 和 t ，判断 s 是否为 t 的子序列。
字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。
进阶：

如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

致谢：
特别感谢 @pbrother 添加此问题并且创建所有测试用例。

示例 1：
输入：s = "abc", t = "ahbgdc"
输出：true

示例 2：
输入：s = "axc", t = "ahbgdc"
输出：false
 
提示：
0 <= s.length <= 100
0 <= t.length <= 10^4
两个字符串都只由小写字符组成。
*/
#include <string>
#include <vector>

class Solution
{
public:
    bool isSubsequence(std::string s, std::string t)
    {
        std::vector<std::vector<int>> dp(t.size()+1, std::vector<int> (s.size()+1, 0));
        for (int i = 1; i < t.size()+1; ++i)
        {
            for (int j = 1; j <=i; ++j)
            {
                if (s[j-1] == t[i-1])
                {
                    dp[i][j] = dp[i-1][j-1]+1;
                }
                else
                    dp[i][j] = dp[i-1][j];
            }
        }
        return dp.back().back() == s.size();
    }
};

class Solution
{
public:
    bool isSubsequence(std::string s, std::string t)
    {
        std::vector<int> dp(s.size()+1, 0);
        for (int i = 0; i < t.size(); ++i)
        {
            for (int j = s.size(); j >= 1;-- j)
            {
                if (s[j-1] == t[i])
                    dp[j] = dp[j-1]+1;
            }
        }
        return dp.back() == s.size();
    }
};