/*
存在重复元素 III
给你一个整数数组 nums 和两个整数 indexDiff 和 valueDiff 。

找出满足下述条件的下标对 (i, j)：

i != j,
abs(i - j) <= indexDiff
abs(nums[i] - nums[j]) <= valueDiff
如果存在，返回 true ；否则，返回 false 。 

示例 1：
输入：nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
输出：true
解释：可以找出 (i, j) = (0, 3) 。
满足下述 3 个条件：
i != j --> 0 != 3
abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0

示例 2：
输入：nums = [1,5,9,1,5,9], indexDiff = 2, valueDiff = 3
输出：false
解释：尝试所有可能的下标对 (i, j) ，均无法满足这 3 个条件，因此返回 false 。
 

提示：
2 <= nums.length <= 105
-109 <= nums[i] <= 109
1 <= indexDiff <= nums.length
0 <= valueDiff <= 109

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/introduction-to-data-structure-binary-search-tree/xpffam/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <vector>
#include <queue>
#include <cmath>

// 超时
class Solution
{
public:
    bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff, int valueDiff)
    {
        if (nums.size() == 0) return false;
        std::queue<int> qu;
        if (nums.size() <= indexDiff)
        {
            for(auto i:nums) qu.emplace(i);
            return findMinDiff(qu, valueDiff);
        }
        for (int i=0; i <= indexDiff; i++)
        {
            qu.emplace(nums[i]);
        }
        for (int i=indexDiff+1; i<nums.size(); ++i)
        {
            if (findMinDiff(qu, valueDiff)) return true;
            qu.pop();
            qu.emplace(nums[i]);
        }
        return findMinDiff(qu, valueDiff);
    }

    bool findMinDiff(std::queue<int> queue, int valueDiff)
    {
        int minDiff = __INT_MAX__;
        std::vector<int> vec;
        while (!queue.empty())
        {
            int value = queue.front();
            queue.pop();
            if (!vec.empty())
            {
                for (auto i:vec)
                {
                    if (std::abs(i-value) <= valueDiff)
                    {
                        return true;
                    }
                }
            }
            vec.emplace_back(value);
        }
        return false;
    }
};