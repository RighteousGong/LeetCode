/*
46. 全排列
中等

给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

示例 1：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

示例 2：
输入：nums = [0,1]
输出：[[0,1],[1,0]]

示例 3：
输入：nums = [1]
输出：[[1]]

提示：
1 <= nums.length <= 6
-10 <= nums[i] <= 10
nums 中的所有整数 互不相同
*/
#include <vector>

class Solution 
{
    std::vector<std::vector<int>> result;
    std::vector<int> path;
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums)
    {
        std::vector<bool> used(nums.size(), false);
        backTracking(nums, used);
        return result;
    }

    void backTracking(std::vector<int>& nums, std::vector<bool>& used)
    {
        if (path.size() == nums.size())
        {
            result.emplace_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); ++i)
        {
            if (used[i])
                continue;
            used[i] = true;
            path.emplace_back(nums[i]);
            backTracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
};