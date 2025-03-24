/*
47. 全排列 II
中等

给定一个可包含重复数字的序列 nums ，按任意顺序 返回所有不重复的全排列。

示例 1：
输入：nums = [1,1,2]
输出：
[[1,1,2],
 [1,2,1],
 [2,1,1]]

示例 2：
输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
 
提示：
1 <= nums.length <= 8
-10 <= nums[i] <= 10
*/
#include <vector>
#include <algorithm>

class Solution
{
    std::vector<std::vector<int>> result;
    std::vector<int> path;
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());
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
            if (used[i] || (i > 0 && nums[i] == nums[i-1] && used[i-1] == true))
                continue;
            used[i] = true;
            path.emplace_back(nums[i]);
            backTracking(nums, used);
            used[i] = false;
            path.pop_back();
        }
    }
};