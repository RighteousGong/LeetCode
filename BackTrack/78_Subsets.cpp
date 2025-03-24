/*
78. 子集
中等
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

示例 1：
输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

示例 2：
输入：nums = [0]
输出：[[],[0]]

提示：
1 <= nums.length <= 10
-10 <= nums[i] <= 10
nums 中的所有元素 互不相同
*/
#include <vector>

class Solution
{
	std::vector<std::vector<int>> result;
	std::vector<int> path;
public:
	std::vector<std::vector<int>> subsets(std::vector<int> nums)
	{
		backTracking(nums, 0);
		return result;
	}

	void backTracking(std::vector<int> nums, int startIndx)
	{
		result.emplace_back(path);
		if (startIndx >= nums.size())
		{
			return;
		}
		for (int i = startIndx; i < nums.size(); ++i)
		{
			path.emplace_back(nums[i]);
			backTracking(nums, i + 1);
			path.pop_back();
		}
	}
};