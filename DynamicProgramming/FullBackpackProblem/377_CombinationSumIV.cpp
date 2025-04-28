/*
377. 组合总和 Ⅳ
中等

给你一个由 不同 整数组成的数组 nums，和一个目标整数 target。请你从 nums 中找出并返回总和为 target 的元素组合的个数。
题目数据保证答案符合 32 位整数范围。

示例 1：
输入：nums = [1,2,3], target = 4
输出：7
解释：
所有可能的组合为：
(1, 1, 1, 1)
(1, 1, 2)
(1, 2, 1)
(1, 3)
(2, 1, 1)
(2, 2)
(3, 1)
请注意，顺序不同的序列被视作不同的组合。

示例 2：
输入：nums = [9], target = 3
输出：0
 
提示：
1 <= nums.length <= 200
1 <= nums[i] <= 1000
nums 中的所有元素 互不相同
1 <= target <= 1000
 
进阶：如果给定的数组中含有负数会发生什么？问题会产生何种变化？如果允许负数出现，需要向题目中添加哪些限制条件？
*/
#include <vector>

class Solution
{
public:
    int combinationSum4(std::vector<int>& nums, int target) // 二维便于理解
    {
        std::vector<std::vector<uint64_t>> dp(nums.size(), std::vector<uint64_t> (target + 1, 0));

        for (int i = nums[0]; i <= target; ++i)
        {
            if (i % nums[0] == 0) dp[0][i] = 1;
        }
        for (int i = 0; i < nums.size(); ++i)
            dp[i][0] = 1;

        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = 0; j <= target; ++j)
            {
                if (nums[i] > j) dp[i][j] = dp[i-1][j];
                else 
                {
                    for (int m = i; m >= 0; --m)
                        if (j - nums[m] >= 0)
                            dp[i][j] += dp[i][j - nums[m]];
                }
            }
        }
        return dp[nums.size()-1][target];
    }

    int combinationSum4(std::vector<int>& nums, int target) // 一维，运行效率更高
    {
        std::vector<uint64_t> dp(target + 1, 0);
        dp[0] = 1;

        for (int i = 0; i <= target; ++i)
        {
            for (int j = 0; j < nums.size(); ++j)
            {
                if (i >= nums[j]) dp[i] += dp[i - nums[j]];
            }
        }
        return dp[target];
    }
};