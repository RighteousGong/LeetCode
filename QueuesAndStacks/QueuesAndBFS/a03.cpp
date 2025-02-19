/*
打开转盘锁
你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。
锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。
列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
字符串 target 代表可以解锁的数字，你需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回 -1 。

示例 1:
输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
输出：6
解释：
可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
因为当拨动到 "0102" 时这个锁就会被锁定。

示例 2:
输入: deadends = ["8888"], target = "0009"
输出：1
解释：把最后一位反向旋转一次即可 "0000" -> "0009"。

示例 3:
输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
输出：-1
解释：无法旋转到目标数字且不被锁定。

提示：
1 <= deadends.length <= 500
deadends[i].length == 4
target.length == 4
target 不在 deadends 之中
target 和 deadends[i] 仅由若干位数字组成

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/queue-stack/kj48j/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <unordered_set>

class Solution 
{
public:
    int openLock(std::vector<std::string>& deadends, std::string target) 
    {
        std::queue<std::string> neiber;
        int stip = -1;
        std::unordered_set<std::string> oddStrs;
        std::unordered_set<std::string> deadendsSet(deadends.begin(), deadends.end());
        if (!deadendsSet.count("0000"))
        {
            neiber.emplace("0000");
            oddStrs.emplace("0000");
        }
        while (!neiber.empty())
        {
            ++ stip;
            int size = neiber.size();

            for (int j = 0; j < size; j++)
            {
                std::string str = neiber.front();
                neiber.pop();
                if (str == target)
                {
                    return stip;
                }

                for (int i = 0; i < str.length(); ++i)
                {
                    std::string tmp1 = str;
                    tmp1[i] = tmp1[i] + 1 > 57 ? 48 : tmp1[i] + 1;
                    if (!oddStrs.count(tmp1) && !deadendsSet.count(tmp1))
                    {
                        neiber.emplace(tmp1);
                        oddStrs.emplace(tmp1);
                    }

                    std::string tmp2 = str;
                    tmp2[i] = tmp2[i] - 1 < 48 ? 57 : tmp2[i] -1;
                    if (!oddStrs.count(tmp2) && !deadendsSet.count(tmp2))
                    {
                        neiber.emplace(tmp2);
                        oddStrs.emplace(tmp2);
                    }
                }
            }
        }
        return -1;
    }
};

int main()
{
    std::vector<std::string> vec = {"0000","8889","8878","8898","8788","8988","7888","9888"};
    std::string lock = "8888";
    Solution sol;
    std::cout << sol.openLock(vec, lock) << std::endl;
}