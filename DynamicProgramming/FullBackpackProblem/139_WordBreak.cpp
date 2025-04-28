/*
139. 单词拆分
中等

给你一个字符串 s 和一个字符串列表 wordDict 作为字典。如果可以利用字典中出现的一个或多个单词拼接出 s 则返回 true。
注意：不要求字典中出现的单词全部都使用，并且字典中的单词可以重复使用。

示例 1：
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以由 "leet" 和 "code" 拼接成。

示例 2：
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以由 "apple" "pen" "apple" 拼接成。
     注意，你可以重复使用字典中的单词。

示例 3：
输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

提示：
1 <= s.length <= 300
1 <= wordDict.length <= 1000
1 <= wordDict[i].length <= 20
s 和 wordDict[i] 仅由小写英文字母组成
wordDict 中的所有字符串 互不相同
*/
#include <vector>
#include <string>
#include <unordered_set>

class Solution
{
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict)
    {
        std::vector<bool> dp(s.size()+1, false);
        std::unordered_set<std::string> wordSet(wordDict.begin(), wordDict.end());

        dp[0] = true;
        for (int i = 0; i < dp.size(); ++i)
        {
            for (int j = i + 1; j <= s.size(); ++j)
            {
                // 0 1 2 3 4 5 6 7 8
                // 1 0 0 0 1 0 0 0 1 
                // l e e t c o d e
                std::string subStr = s.substr(i, j - i);
                if (wordSet.find(subStr) != wordSet.end() && dp[i])
                    dp[j] = true;
            }
        }
        return dp[s.size()];
    }
};