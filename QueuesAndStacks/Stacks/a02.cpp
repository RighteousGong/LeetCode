/*
有效的括号
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。

示例 1：
输入：s = "()"
输出：true

示例 2：
输入：s = "()[]{}"
输出：true

示例 3：
输入：s = "(]"
输出：false

示例 4：
输入：s = "([])"
输出：true

提示：
1 <= s.length <= 104
s 仅由括号 '()[]{}' 组成
相关标签
C++

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/queue-stack/g9d0h/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <stack>
#include <string>

class Solution {
public:
    bool isValid(std::string s) 
    {
        std::stack<char> rights;
        if (s.size() % 2 == 1)
        {
            return false;
        }
        for (auto str : s)
        {
            if (str == '(')
                rights.emplace(')');
            if (str == '{')
                rights.emplace('}');
            if (str == '[')
                rights.emplace(']'); 
                
            if (str == ')')
            {
                if (!rights.empty() && rights.top() == ')')
                    rights.pop();
                else
                    return false;
            }
            if (str == '}')
            {
                if (!rights.empty() && rights.top() == '}')
                    rights.pop();
                else
                    return false;
            }
            if (str == ']')
            {
                if (!rights.empty() && rights.top() == ']')
                    rights.pop();
                else
                    return false;
            }
        }
        if (rights.empty())
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};