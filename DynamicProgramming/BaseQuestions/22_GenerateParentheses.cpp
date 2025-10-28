/*
22. Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]
 

Constraints:

1 <= n <= 8

*/
#include <string>
#include <vector>
#include <algorithm>


// 溯回
class Solution {
public:
    std::string stack = "";
    std::vector<std::string> result;

    void backtrack(int close, int open, int n)
    {
        if (close == open && close == n)
        {
            result.push_back(stack);
            return;
        }
        if (open < n)
        {
            stack.push_back('(');
            backtrack(close, open + 1, n);
            stack.pop_back();
        }
        if (close < open)
        {
            stack.push_back(')');
            backtrack(close + 1, open, n);
            stack.pop_back();
        }
    }

    std::vector<std::string> generateParenthesis(int n)
    {
        backtrack(0, 0, n);
        return result;
    }
};

// 动态规划 需要用到卡特兰数
class Solution {
public:
    std::vector<std::string> generateParenthesis(int n)
    {
        std::vector<std::vector<std::string>> backage(n+1);
        backage[0] = {""};

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 0; j < i; ++ j)
            {
                for (auto& left: backage[j])
                {
                    for (auto& right: backage[i-1 - j])
                    {
                        std::string str = "(" + left + ")" + right;
                        backage[i].push_back(str);
                    }
                }
            }
        }

        return backage[n];
    }
};