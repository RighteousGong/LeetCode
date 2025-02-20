/*
每日温度
给定一个整数数组 temperatures ，表示每天的温度，返回一个数组 answer ，其中 answer[i] 是指对于第 i 天，下一个更高温度出现在几天后。如果气温在这之后都不会升高，请在该位置用 0 来代替。

示例 1:
输入: temperatures = [73,74,75,71,69,72,76,73]
输出: [1,1,4,2,1,1,0,0]

示例 2:
输入: temperatures = [30,40,50,60]
输出: [1,1,1,0]

示例 3:
输入: temperatures = [30,60,90]
输出: [1,1,0]

提示：

1 <= temperatures.length <= 105
30 <= temperatures[i] <= 100

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/queue-stack/genw3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <vector>
#include <stack>

class Solution 
{
public:
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures)
    {
        if (temperatures.size() <= 1)
        {
            return temperatures;
        }
        std::stack<int> day;
        for (int i=0; i<temperatures.size(); ++i)
        {
            while (!day.empty() && temperatures[i] > temperatures[day.top()])
            {
                temperatures[day.top()] = i - day.top();
                day.pop();
            }
            day.emplace(i);
        }
        while (!day.empty())
        {
            temperatures[day.top()] = 0;
            day.pop();
        }
        
        return temperatures;
    }
};