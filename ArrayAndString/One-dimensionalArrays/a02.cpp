/*
搜索插入位置

给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
请必须使用时间复杂度为 O(log n) 的算法。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/cxqdh/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>

int searchInsert(std::vector<int>& nums, int target);

int main(){
    std::vector<int> nums = {1,3,5,6};
    int index = searchInsert(nums, 2);
    std::cout << index << std::endl;
}

int searchInsert(std::vector<int>& nums, int target){
    int start = 0, end = nums.size() - 1;
    while (start <= end){
        int index = (start + end) / 2;
        if(nums[index] == target){
            return index;
        }else if(nums[index] < target){
            start = index + 1;
        }else{
            end = index - 1;
        }
    }
    return start;
}