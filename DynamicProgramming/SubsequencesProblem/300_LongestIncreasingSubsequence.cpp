/*
300. 最长递增子序列
中等
给你一个整数数组 nums ，找到其中最长严格递增子序列的长度。

子序列 是由数组派生而来的序列，删除（或不删除）数组中的元素而不改变其余元素的顺序。例如，[3,6,2,7] 是数组 [0,3,1,6,2,2,7] 的子序列。

示例 1：

输入：nums = [10,9,2,5,3,7,101,18]
输出：4
解释：最长递增子序列是 [2,3,7,101]，因此长度为 4 。
示例 2：

输入：nums = [0,1,0,3,2,3]
输出：4
示例 3：

输入：nums = [7,7,7,7,7,7,7]
输出：1

提示：
1 <= nums.length <= 2500
-104 <= nums[i] <= 104

进阶：

你能将算法的时间复杂度降低到 O(n log(n)) 吗?
*/
#include <vector>

class Solution 
{
public:
    int lengthOfLIS(std::vector<int>& nums) 
    {
        std::vector<int> dp(nums.size(), 1);
        int result = 1;
        for (int i = 1; i < nums.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (nums[i] > nums[j])
                    dp[i] = std::max(dp[i], dp[j]+1); // 如果是dp[i]+1会累加所有比dp[i]小的数 
            }
            if (result < dp[i])
                result = dp[i];
        }
        return result;
    }
};