/*
416. 分割等和子集
中等

给你一个 只包含正整数 的 非空 数组 nums 。请你判断是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。

示例 1：
输入：nums = [1,5,11,5]
输出：true
解释：数组可以分割成 [1, 5, 5] 和 [11] 。

示例 2：
输入：nums = [1,2,3,5]
输出：false
解释：数组不能分割成两个元素和相等的子集。
 
提示：
1 <= nums.length <= 200
1 <= nums[i] <= 100
*/
#include <vector>

class Solution 
{
public:
    bool canPartition(std::vector<int>& nums)
    {
        int sum = 0;
        for (auto i : nums)
            sum += i;
        if (sum%2 == 1) return false;
        std::vector<int> dp(10001, 0);

        int target = sum/2;

        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = target; j >= nums[i]; --j)
            {
                dp[j] = std::max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }

        if (dp[target] == target)
            return true;
        return false;
    }
};