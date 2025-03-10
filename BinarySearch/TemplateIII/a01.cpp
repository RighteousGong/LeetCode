/*
在排序数组中查找元素的第一个和最后一个位置
给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。请你找出给定目标值在数组中的开始位置和结束位置。

如果数组中不存在目标值 target，返回 [-1, -1]。

你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。

示例 1：
输入：nums = [5,7,7,8,8,10], target = 8
输出：[3,4]

示例 2：
输入：nums = [5,7,7,8,8,10], target = 6
输出：[-1,-1]

示例 3：
输入：nums = [], target = 0
输出：[-1,-1]
 

提示：
0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums 是一个非递减数组
-109 <= target <= 109

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/binary-search/xenp13/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <vector>

class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target)
    {
        if (nums.size() == 0) return {-1, -1};
        int left = findFirst(nums, target);
        if (left == -1) return {-1, -1};
        int right = findEnd(nums, target);
        return {left, right};
    }

    int findFirst(std::vector<int>& nums, int target)
    {
        int left = 0, right = nums.size()-1;
        while (left <= right)
        {
            int mid = left + (right-left)/2;
            if (nums[mid] >= target) right = mid - 1;
            if (nums[mid] < target) left  = mid + 1;
        }
        if (left >= nums.size() || nums[left] != target) return -1;
        return left;
    }

    int findEnd(std::vector<int>& nums, int target)
    {
        int left = 0, right = nums.size()-1;
        while (left <= right)
        {
            int mid = left + (right-left)/2;
            if (nums[mid] > target) right = mid - 1;
            if (nums[mid] <= target) left  = mid + 1;
        }
        if (right < 0 || nums[right] != target) return -1;
        return right;
    }
};