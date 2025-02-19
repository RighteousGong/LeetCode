/*
给你一个整数 n ，返回 和为 n 的完全平方数的最少数量 。
完全平方数 是一个整数，其值等于另一个整数的平方；换句话说，其值等于一个整数自乘的积。例如，1、4、9 和 16 都是完全平方数，而 3 和 11 不是。

示例 1：
输入：n = 12
输出：3 
解释：12 = 4 + 4 + 4

示例 2：
输入：n = 13
输出：2
解释：13 = 4 + 9
 
提示：
1 <= n <= 104

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/queue-stack/kfgtt/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <vector>
#include <queue>
#include <unordered_set>

class Solution 
{
public:
    int numSquares(int n) 
    {
        int base = 1;
        std::vector<int> squares;
        std::vector<bool> visited(n + 1, false);
        visited[n] = true;
        while (base * base <= n) 
        {
            squares.push_back(base * base);
            ++base;
        }
        
        std::queue<int> neiber;
        neiber.emplace(n);
        int stip = -1;
        while (!neiber.empty())
        {
            ++ stip;
            int size = neiber.size();

            for (int i = 0; i < size; ++ i)
            {
                int number = neiber.front();
                neiber.pop();

                if (number == 0)
                {
                    return stip;
                }

                int j = 0;
                while (j < squares.size() && squares[j] <= number)
                {
                    int next = number - squares[j];
                    if (!visited[next])
                    {
                        neiber.emplace(number - squares[j]);
                        visited[next] = true;
                    }
                    ++ j;
                }
            }
        }
        return n;
    }
};