/*
90. 子集 II
中等

给你一个整数数组 nums ，其中可能包含重复元素，请你返回该数组所有可能的 子集（幂集）。

解集 不能 包含重复的子集。返回的解集中，子集可以按 任意顺序 排列。 

示例 1：
输入：nums = [1,2,2]
输出：[[],[1],[1,2],[1,2,2],[2],[2,2]]

示例 2：
输入：nums = [0]
输出：[[],[0]]

提示：
1 <= nums.length <= 10
-10 <= nums[i] <= 10
*/
#include <vector>
#include <algorithm>

class Solution 
{
    std::vector<std::vector<int>> result;
    std::vector<int> path;
public:
    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) 
    {
        std::sort(nums.begin(), nums.end());
        backTracking(0, nums);
        return result;
    }

    void backTracking(int startIndex, std::vector<int>& nums)
    {
        result.emplace_back(path);
        for (int i = startIndex; i < nums.size(); ++i)
        {
            if (i > startIndex && nums[i] == nums[i-1])
                continue;
            path.emplace_back(nums[i]);
            backTracking(i+1, nums);
            path.pop_back();
        }
    }
};