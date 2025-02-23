/*
01 矩阵
给定一个由 0 和 1 组成的矩阵 mat ，请输出一个大小相同的矩阵，其中每一个格子是 mat 中对应位置元素到最近的 0 的距离。

两个相邻元素间的距离为 1 。

示例 1：
输入：mat = [[0,0,0],[0,1,0],[0,0,0]]
输出：[[0,0,0],[0,1,0],[0,0,0]]

示例 2：
输入：mat = [[0,0,0],[0,1,0],[1,1,1]]
输出：[[0,0,0],[0,1,0],[1,2,1]]

提示：

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
mat 中至少有一个 0 

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/queue-stack/g7pyt/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <vector>
#include <queue>
#include <utility>

// 目前有问题
class Solution 
{
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) 
    {
        std::vector<std::vector<int>> vec(mat.size(), std::vector<int>(mat[0].size(), false));
        for (int i=0; i<mat.size(); ++i)
        {
            for (int j=0; j<mat.size(); ++j)
            {
                BFS(mat, vec, i, j);
            }
        }
        return mat;
    }

    void BFS(std::vector<std::vector<int>>& mat, std::vector<std::vector<int>>& vec, int high, int weight)
    {
        if (vec[high][weight])
        {
            return;
        }
        int min = mat.size() > mat[0].size() ? mat.size() : mat[0].size();
        std::pair<int, int> cur(high, weight);
        vec[high][weight] = true;
        if (mat[high][weight] == 0)
        {
            return;
        }
        std::pair<int, int> up(high - 1, weight); // 上 
        std::pair<int, int> down(high + 1, weight); // 下
        std::pair<int, int> left(high, weight-1); // 左
        std::pair<int, int> right(high, weight+1); // 右

        if (up.first >= 0)
        {
            BFS(mat, vec, up.first, up.second);
            int t = mat[up.first][up.second] + 1;
            min = min > t ? t : min;
        }
        if (down.first < mat.size())
        {
            BFS(mat, vec, down.first, down.second);
            int t = mat[down.first][down.second] + 1;
            min = min > t ? t : min;
        }
        if (left.second >= 0)
        {
            BFS(mat, vec, left.first, left.second);
            int t = mat[left.first][left.second] + 1;
            min = min > t ? t : min;
        }
        if (right.second < mat[0].size())
        {
            BFS(mat, vec, right.first, right.second);
            int t = mat[right.first][right.second] + 1;
            min = min > t ? t : min;
        }
        mat[high][weight] = min;
    }
};

class Solution 
{
public:
    std::vector<std::vector<int>> updateMatrix(std::vector<std::vector<int>>& mat) 
    {
        int m = mat.size(), n = mat[0].size();
        std::vector<std::vector<int>> dist(m, std::vector<int>(n, -1)); // 初始化距离矩阵为-1
        std::queue<std::pair<int, int>> q;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        std::vector<std::pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();

            for (auto& dir : directions) {
                int new_x = x + dir.first;
                int new_y = y + dir.second;

                if (new_x >= 0 && new_x < m && new_y >= 0 && new_y < n && dist[new_x][new_y] == -1) {
                    dist[new_x][new_y] = dist[x][y] + 1;
                    q.push({new_x, new_y});
                }
            }
        }

        return dist;
    }
};