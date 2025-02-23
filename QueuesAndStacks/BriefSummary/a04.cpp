/*
图像渲染
有一幅以 m x n 的二维整数数组表示的图画 image ，其中 image[i][j] 表示该图画的像素值大小。你也被给予三个整数 sr ,  sc 和 color 。你应该从像素 image[sr][sc] 开始对图像进行上色 填充 。

为了完成 上色工作：

从初始像素开始，将其颜色改为 color。
对初始坐标的 上下左右四个方向上 相邻且与初始像素的原始颜色同色的像素点执行相同操作。
通过检查与初始像素的原始颜色相同的相邻像素并修改其颜色来继续 重复 此过程。
当 没有 其它原始颜色的相邻像素时 停止 操作。
最后返回经过上色渲染 修改 后的图像 。

示例 1:
输入：image = [[1,1,1],[1,1,0],[1,0,1]]，sr = 1, sc = 1, color = 2
输出：[[2,2,2],[2,2,0],[2,0,1]]
解释：在图像的正中间，坐标 (sr,sc)=(1,1) （即红色像素）,在路径上所有符合条件的像素点的颜色都被更改成相同的新颜色（即蓝色像素）。
注意，右下角的像素 没有 更改为2，因为它不是在上下左右四个方向上与初始点相连的像素点。
 
示例 2:
输入：image = [[0,0,0],[0,0,0]], sr = 0, sc = 0, color = 0
输出：[[0,0,0],[0,0,0]]
解释：初始像素已经用 0 着色，这与目标颜色相同。因此，不会对图像进行任何更改。 

提示:

m == image.length
n == image[i].length
1 <= m, n <= 50
0 <= image[i][j], color < 216
0 <= sr < m
0 <= sc < n

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/queue-stack/g02cj/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <vector>
#include <utility>
#include <queue>

class Solution 
{
    std::queue<std::pair<int, int>> neiber;
public:
    std::vector<std::vector<int>> floodFill(std::vector<std::vector<int>>& image, int sr, int sc, int color) 
    {
        if (image.size() == 0 || image[0].size() == 0)
        {
            return image;
        }

        int target = image[sr][sc];
        if (color == target)
        {
            return image;
        }
        neiber.emplace(std::pair<int, int>(sr, sc));
        image[sr][sc] = color;
        while (!neiber.empty())
        {
            BFS(image, target, color);
        }
        return image;
    }

    void BFS(std::vector<std::vector<int>>& image, int target, int color)
    {
        std::pair<int, int> cur = neiber.front();

        const int weight = image[0].size();
        const int high   = image.size();

        std::pair<int, int> up(cur.first - 1, cur.second); // 上 
        if (up.first >= 0 && image[up.first][up.second] == target)
        {
            image[up.first][up.second] = color;
            neiber.emplace(up);
        }
        std::pair<int, int> down(cur.first + 1, cur.second); // 下
        if (down.first < high && image[down.first][down.second] == target)
        {
            image[down.first][down.second] = color;
            neiber.emplace(down);
        }
        std::pair<int, int> left(cur.first, cur.second - 1); // 左
        if (left.second >= 0 && image[left.first][left.second] == target)
        {
            image[left.first][left.second] = color;
            neiber.emplace(left);
        }
        std::pair<int, int> right(cur.first, cur.second + 1); // 右
        if (right.second < weight && image[right.first][right.second] == target)
        {
            image[right.first][right.second] = color;
            neiber.emplace(right);
        }
        neiber.pop();
    }
};