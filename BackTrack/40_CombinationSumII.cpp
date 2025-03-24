/*
40. 组合总和 II
中等
给定一个候选人编号的集合 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
candidates 中的每个数字在每个组合中只能使用 一次 。
注意：解集不能包含重复的组合。

示例 1:
输入: candidates = [10,1,2,7,6,1,5], target = 8,
输出:
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]

示例 2:
输入: candidates = [2,5,2,1,2], target = 5,
输出:
[
[1,2,2],
[5]
]

提示:

1 <= candidates.length <= 100
1 <= candidates[i] <= 50
1 <= target <= 30
*/
#include <vector>
#include <algorithm>

class Solution 
{
	std::vector<std::vector<int>> result;
	std::vector<int> path;
	std::vector<std::vector<int>> vec;

public:
	std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target)
	{
		sort(candidates.begin(), candidates.end());
		backTracking(candidates, target, 0, 0);
		return result;
	}

	void backTracking(std::vector<int>& candidates, int target, int sum, int startIndex)
	{
		if (sum == target)
		{
			result.emplace_back(path);
			return;
		}
		for (int i = startIndex; i < candidates.size() && sum + candidates[i] <= target; ++i)
		{
			if (i > startIndex && candidates[i] == candidates[i - 1]) 
			{
				continue;
			}
			path.emplace_back(candidates[i]);
			sum += candidates[i];
			backTracking(candidates, target, sum, i + 1);
			sum -= candidates[i];
			path.pop_back();
		}
	}
};