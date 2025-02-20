/*
最小栈
设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。

实现 MinStack 类:

MinStack() 初始化堆栈对象。
void push(int val) 将元素val推入堆栈。
void pop() 删除堆栈顶部的元素。
int top() 获取堆栈顶部的元素。
int getMin() 获取堆栈中的最小元素。
 

示例 1:
输入：
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]
输出：
[null,null,null,null,-3,null,0,-2]

解释：
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin();   --> 返回 -3.
minStack.pop();
minStack.top();      --> 返回 0.
minStack.getMin();   --> 返回 -2.

提示：
-231 <= val <= 231 - 1
pop、top 和 getMin 操作总是在 非空栈 上调用
push, pop, top, and getMin最多被调用 3 * 104 次

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/queue-stack/g5l7d/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <vector>

class MinStack {
public:
    MinStack() 
    {
        min = 0;
    }
    
    void push(int val) 
    {
        if (data.empty())
        {
            min = val;
        }
        else
        {
            if (min > val)
            {
                min = val;
            }
        }
        data.push_back(val);
    }
    
    void pop() 
    {
        if (data.empty())
        {
            return;
        }
        int curr = data.back();
        data.pop_back();
        if (data.empty())
        {
            min = 0;
            return;
        }
        if (curr == min)
        {
            min = data[0];
            for (auto i : data)
            {
                if (i < min)
                {
                    min = i;
                }
            }
        }
    }
    
    int top() 
    {
        if (data.empty())
        {
            return NULL;
        }
        return data.back();    
    }
    
    int getMin() 
    {
        return min;
    }
private:
    std::vector<int> data;
    int min;
};