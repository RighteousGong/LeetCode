/*
55. Jump Game

You are given an integer array nums. You are initially positioned at the array's first index,
and each element in the array represents your maximum jump length at that position.
Return true if you can reach the last index, or false otherwise. 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 104
0 <= nums[i] <= 105
*/
#include <vector>

// 贪心
class Solution {
public:
    bool canJump(std::vector<int>& nums)
    {
        if (nums.size() == 1)
            return true;
        if (nums[0] == 0) 
            return false; // 起点无法跳动
        int end = nums[0];
        int i = 1;
        while (i <= end  && i < nums.size())
        {
            if (nums[i] + i > end)
                end = nums[i] + i;

            if (end >= nums.size()-1)
                return true;
            ++ i;
        }

        return false;
    }
};

// 动态规划
class Solution {
public:
    bool canJump(std::vector<int>& nums)
    {
        if (nums.size() == 1)
            return true;
        std::vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        for (int i = 1; i < nums.size(); ++ i)
        {
            if (i > dp[i -1])
                dp[i] = dp[i -1];
            else
            {
                if (i + nums[i] > dp[i-1])
                    dp[i] = i + nums[i];
                else
                    dp[i] = dp[i-1];
            }
        }

        if (dp[nums.size()-1] >= nums.size()-1)
            return true;
        else
            return false;
    }
};