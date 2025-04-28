/*
718. 最长重复子数组
中等

提示
给两个整数数组 nums1 和 nums2 ，返回 两个数组中 公共的 、长度最长的子数组的长度 。

示例 1：

输入：nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
输出：3
解释：长度最长的公共子数组是 [3,2,1] 。
示例 2：

输入：nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
输出：5
 
提示：
1 <= nums1.length, nums2.length <= 1000
0 <= nums1[i], nums2[i] <= 100
*/
#include <vector>

class Solution
{
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::vector<std::vector<int>> dp(nums1.size(), std::vector<int>(nums2.size(), 0));
        int result = 0;
        for (int i = 0; i < dp.size(); ++ i)
        {
            for (int j = 0; j < nums2.size(); ++ j)
            {
                if (nums1[i] == nums2[j])
                {
                    if (i > 0 && j > 0)
                        dp[i][j] = dp[i-1][j-1] + 1;
                    else
                        dp[i][j] = 1;
                }
                if (dp[i][j] > result) result = dp[i][j];
            }
        }
        return result;
    }
};

class Solution
{
public:
    int findLength(std::vector<int>& nums1, std::vector<int>& nums2)
    {
        std::vector<int> dp(nums1.size(), 0);
        int result = 0;
        for (int i = 0; i < dp.size(); ++ i)
        {
            for (int j = nums2.size() - 1; j >= 0; -- j)
            {
                if (nums1[i] == nums2[j])
                {
                    if (j > 0)
                        dp[j] = dp[j-1] + 1;
                    else
                        dp[j] = 1;
                }
                else
                    dp[j] = 0;
                if (dp[j] > result) result = dp[j];
            }
        }
        return result;
    }
};