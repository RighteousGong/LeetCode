/*
45. Jump Game II

You are given a 0-indexed array of integers nums of length n. You are initially positioned at index 0.
Each element nums[i] represents the maximum length of a forward jump from index i. 
In other words, if you are at index i, you can jump to any index (i + j) where:

0 <= j <= nums[i] and
i + j < n
Return the minimum number of jumps to reach index n - 1. The test cases are generated such that you can reach index n - 1.

Example 1:

Input: nums = [2,3,1,1,4]
Output: 2
Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [2,3,0,1,4]
Output: 2
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 1000
It's guaranteed that you can reach nums[n - 1].
*/
#include <vector>

// 动态规划 O(n²)
class Solution
 {
public:
    int jump(std::vector<int>& nums) 
    {
        int size = nums.size();
        std::vector<int> dp(size, 65535);
        dp[0] = 0;

        for (int i = 0; i < size; ++i)
        {
            dp[i] = std::min(dp[i], i);
            for (int j = i; j <= nums[i] + i && j < size; ++ j)
                dp[j] = std::min(dp[i] + 1, dp[j]);
        }

        return dp[size-1];
    }
};

// 贪心 O(n)
class Solution {
public:
    int jump(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        int steps = 0;       // 记录跳的次数
        int end = 0;         // 当前层的最远可达边界
        int farthest = 0;    // 下一层的最远可达边界

        for (int i = 0; i < n - 1; ++i) {
            farthest = std::max(farthest, i + nums[i]);

            // 到达当前层的边界，必须跳一次
            if (i == end) 
            {
                ++steps;
                end = farthest; // 更新下一层的边界
            }
        }

        return steps;
    }
};