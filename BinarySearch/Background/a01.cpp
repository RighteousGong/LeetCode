/*
二分查找
给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。

示例 1:
输入: nums = [-1,0,3,5,9,12], target = 9
输出: 4
解释: 9 出现在 nums 中并且下标为 4

示例 2:
输入: nums = [-1,0,3,5,9,12], target = 2
输出: -1
解释: 2 不存在 nums 中因此返回 -1
 
提示：
你可以假设 nums 中的所有元素是不重复的。
n 将在 [1, 10000]之间。
nums 的每个元素都将在 [-9999, 9999]之间。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/binary-search/xexoac/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <vector>

class Solution
{
public:
    int search(std::vector<int>& nums, int target)
    {
        int left  = 0;
        int right = nums.size()-1;
        while (left <= right)
        {
            int index = left + (right-left)/2;
            int val = nums[index];
            if (target == val) return index;
            if (target < val) right = index - 1;
            if (target > val) left  = index + 1;
        }
        return -1;
    }
};