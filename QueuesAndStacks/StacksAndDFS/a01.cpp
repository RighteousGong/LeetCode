/*
岛屿数量
给你一个由 '1'（陆地）和 '0'（水）组成的的二维网格，请你计算网格中岛屿的数量。

岛屿总是被水包围，并且每座岛屿只能由水平方向和/或竖直方向上相邻的陆地连接形成。

此外，你可以假设该网格的四条边均被水包围。

示例 1：
输入：grid = [
  ["1","1","1","1","0"],
  ["1","1","0","1","0"],
  ["1","1","0","0","0"],
  ["0","0","0","0","0"]
]
输出：1

示例 2：
输入：grid = [
  ["1","1","0","0","0"],
  ["1","1","0","0","0"],
  ["0","0","1","0","0"],
  ["0","0","0","1","1"]
]
输出：3

提示：
m == grid.length
n == grid[i].length
1 <= m, n <= 300
grid[i][j] 的值为 '0' 或 '1'

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/queue-stack/kbcqv/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <stack>
#include <utility>

class Solution 
{
public:
    int numIslands(std::vector<std::vector<char>>& grid) 
    {
        int sum = 0;
        std::stack<std::pair<int, int>> land;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++ j)
            {
                if (grid[i][j] == '1')
                {
                    ++ sum;
                    land.emplace(std::pair<int, int> (i, j));
                    DFS(grid, land);
                }
            }
        }
        return sum;
    }

    void DFS(std::vector<std::vector<char>>& grid, std::stack<std::pair<int, int>>& land)
    {
        std::pair<int, int> nowLand = land.top();
        int high = nowLand.first;
        int weight = nowLand.second;
        grid[high][weight] = '0';
        const int maxWeight = grid[0].size();
        const int maxHigh   = grid.size();

        std::pair<int, int> up(high-1, weight); // 上
        if (up.first >= 0 && grid[up.first][up.second] == '1')
        {
            land.emplace(up);
            DFS(grid, land);
        }

        std::pair<int, int> down(high+1, weight); // 下
        if (down.first < maxHigh && grid[down.first][down.second] == '1')
        {
            land.emplace(down);
            DFS(grid, land);
        }

        std::pair<int, int> left(high, weight-1); // 左
        if (left.second >= 0 && grid[left.first][left.second] == '1')
        {
            land.emplace(left);
            DFS(grid, land);
        }

        std::pair<int, int> right(high, weight+1); // 右
        if (right.second < maxWeight && grid[right.first][right.second] == '1')
        {
            land.emplace(right);
            DFS(grid, land);
        }
        land.pop();
    } 
};