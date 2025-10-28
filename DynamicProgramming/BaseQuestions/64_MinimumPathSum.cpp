/*
64. Minimum Path Sum
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.
Note: You can only move either down or right at any point in time.

Example 1:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12
 
Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 200
0 <= grid[i][j] <= 200
*/
#include <vector>

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid)
    {
        std::vector<std::vector<int>> db(grid.size(), std::vector<int>(grid[0].size(), 0));
        db[0][0] = grid[0][0];
        for (int i = 1; i < grid.size(); ++i)
            db[i][0] = grid[i][0] + db[i-1][0];

        for (int i = 1; i < grid[0].size(); ++i)
            db[0][i] = grid[0][i] + db[0][i-1];
        
        for (int i = 1; i < grid.size(); ++i)
        {
            for (int j = 1; j < grid[0].size(); ++j)
            {
                db[i][j] = std::min(db[i][j-1] + grid[i][j], db[i-1][j] + grid[i][j]);
            }
        }

        return db[db.size()-1][db[0].size()-1];
    }
};

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid)
    {
        std::vector<int> db(grid[0].size(), 0);
        db[0] = grid[0][0];
        for (int i = 1; i < grid[0].size(); ++i)
            db[i] = grid[0][i] + db[i-1];
        
        for (int i = 1; i < grid.size(); ++i)
        {
            db[0] += grid[i][0];
            for (int j = 1; j < grid[0].size(); ++j)
            {
                db[j] = std::min(db[j-1], db[j]) + grid[i][j];
            }
        }

        return db[db.size()-1];
    }
};