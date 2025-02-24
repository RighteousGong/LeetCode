/*
钥匙和房间
有 n 个房间，房间按从 0 到 n - 1 编号。最初，除 0 号房间外的其余所有房间都被锁住。你的目标是进入所有的房间。然而，你不能在没有获得钥匙的时候进入锁住的房间。

当你进入一个房间，你可能会在里面找到一套 不同的钥匙，每把钥匙上都有对应的房间号，即表示钥匙可以打开的房间。你可以拿上所有钥匙去解锁其他房间。

给你一个数组 rooms 其中 rooms[i] 是你进入 i 号房间可以获得的钥匙集合。如果能进入 所有 房间返回 true，否则返回 false。

示例 1：
输入：rooms = [[1],[2],[3],[]]
输出：true
解释：
我们从 0 号房间开始，拿到钥匙 1。
之后我们去 1 号房间，拿到钥匙 2。
然后我们去 2 号房间，拿到钥匙 3。
最后我们去了 3 号房间。
由于我们能够进入每个房间，我们返回 true。

示例 2：
输入：rooms = [[1,3],[3,0,1],[2],[0]]
输出：false
解释：我们不能进入 2 号房间。

提示：
n == rooms.length
2 <= n <= 1000
0 <= rooms[i].length <= 1000
1 <= sum(rooms[i].length) <= 3000
0 <= rooms[i][j] < n
所有 rooms[i] 的值 互不相同

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/queue-stack/gle1r/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <vector>
#include <queue>

class Solution 
{
public:
    bool canVisitAllRooms(std::vector<std::vector<int>>& rooms) 
    {
        std::vector<bool> vec(rooms.size(), false);
        int count = 1;
        std::queue<int> numQueue;
        if (rooms[0].size() != 0)
        {
            for (auto i : rooms[0])
            {
                if (!vec[i])
                {
                    numQueue.emplace(i);
                    vec[i] = true;
                    ++ count;
                }
            }
        }
        else
        {
            return false;
        }

        vec[0] = true;
        while (!numQueue.empty())
        {
            int index = numQueue.front();
            numQueue.pop();
            for (auto i:rooms[index])
            {
                if (!vec[i])
                {
                    numQueue.emplace(i);
                    vec[i] = true;
                    ++ count;
                }
            }
            if (count == rooms.size())
            {
                return true;
            }
        }
        return false;
    }
};