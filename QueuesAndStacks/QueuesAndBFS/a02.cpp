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
#include <queue>
#include <set>
#include <utility>

// 用集合存储已经遍历过的节点，内存开销大
class Solution 
{
public:
    int numIslands(std::vector<std::vector<char>>& grid) 
    {
        int sum = 0;
        std::set<std::pair<int, int>> landSet;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++ j)
            {
                if (grid[i][j] == '1')
                {
                    std::pair<int, int> land(i, j); 
                    if (landSet.count(land))
                    {
                        continue;
                    }
                    else
                    {
                        ++ sum;
                        addLand(grid, landSet, i, j);
                    }
                }
            }
        }
        return sum;
    }

    void addLand(std::vector<std::vector<char>>& grid, std::set<std::pair<int, int>>& landSet,int high, int weight)
    {
        std::queue<std::pair<int, int>> neiber;
        neiber.emplace(std::pair<int, int> (high, weight));
        const int maxWeight = grid[0].size();
        const int maxHigh   = grid.size();
        while (!neiber.empty())
        {
            std::pair<int, int> nowLand = neiber.front();
            high = nowLand.first;
            weight = nowLand.second;
            neiber.pop();
            landSet.emplace(std::pair<int, int> (high, weight));

            std::pair<int, int> up(high-1, weight); // 上
            if (!landSet.count(up) && up.first >= 0 && grid[up.first][up.second] == '1')
            {
                landSet.emplace(up);
                neiber.emplace(up);
            }

            std::pair<int, int> down(high+1, weight); // 下
            if (!landSet.count(down) && down.first < maxHigh && grid[down.first][down.second] == '1')
            {
                landSet.emplace(down);
                neiber.emplace(down);
            }

            std::pair<int, int> left(high, weight-1); // 左
            if (!landSet.count(left) && left.second >= 0 && grid[left.first][left.second] == '1')
            {
                landSet.emplace(left);
                neiber.emplace(left);
            }

            std::pair<int, int> right(high, weight+1); // 右
            if (!landSet.count(right) && right.second < maxWeight && grid[right.first][right.second] == '1')
            {
                landSet.emplace(right);
                neiber.emplace(right);
            }
        }
    }
};

// 直接将遍历过的节点设为0
class Solution 
{
public:
    int numIslands(std::vector<std::vector<char>>& grid) 
    {
        int sum = 0;
        for (int i = 0; i < grid.size(); ++i)
        {
            for (int j = 0; j < grid[0].size(); ++ j)
            {
                if (grid[i][j] == '1')
                {
                    ++ sum;
                    addLand(grid, i, j);
                }
            }
        }
        return sum;
    }

    void addLand(std::vector<std::vector<char>>& grid,int high, int weight)
    {
        std::queue<std::pair<int, int>> neiber;
        neiber.emplace(std::pair<int, int> (high, weight));
        grid[high][weight] = '0';
        const int maxWeight = grid[0].size();
        const int maxHigh   = grid.size();
        while (!neiber.empty())
        {
            std::pair<int, int> nowLand = neiber.front();
            high = nowLand.first;
            weight = nowLand.second;
            neiber.pop();

            std::pair<int, int> up(high-1, weight); // 上
            if (up.first >= 0 && grid[up.first][up.second] == '1')
            {
                neiber.emplace(up);
                grid[up.first][up.second] = '0';
            }

            std::pair<int, int> down(high+1, weight); // 下
            if (down.first < maxHigh && grid[down.first][down.second] == '1')
            {
                neiber.emplace(down);
                grid[down.first][down.second] = '0';
            }

            std::pair<int, int> left(high, weight-1); // 左
            if (left.second >= 0 && grid[left.first][left.second] == '1')
            {
                neiber.emplace(left);
                grid[left.first][left.second] = '0';
            }

            std::pair<int, int> right(high, weight+1); // 右
            if (right.second < maxWeight && grid[right.first][right.second] == '1')
            {
                neiber.emplace(right);
                grid[right.first][right.second] = '0';
            }
        }
    }
};


int main() {
    // 使用初始化列表直接初始化二维数组
    std::vector<std::vector<char>> arr1 = {
        {'1', '1', '1', '0', '0'},
        {'1', '1', '0', '0', '0'},
        {'0', '0', '1', '0', '0'},
        {'0', '0', '0', '1', '1'}
    };

    std::vector<std::vector<char>> arr2 = {
        {'1', '1', '1'},
        {'0', '1', '0'},
        {'1', '1', '1'}
    };

    Solution sol;
    std::cout << sol.numIslands(arr2) << std::endl;
}