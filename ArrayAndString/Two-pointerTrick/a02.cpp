/*
数组拆分 I
给定长度为 2n 的整数数组 nums ，你的任务是将这些数分成 n 对, 例如 (a1, b1), (a2, b2), ..., (an, bn) ，
使得从 1 到 n 的 min(ai, bi) 总和最大。

返回该最大总和 。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/c24he/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>

int arrayPairSum(std::vector<int>& nums);
void quickSort(std::vector<int>& nums, int start, int end);

int main(){
    std::vector<int> nums = {6,2,6,5,1,2};
    int max = arrayPairSum(nums);
    std::cout << max;
}

int arrayPairSum(std::vector<int>& nums) {
    int max = 0;
    quickSort(nums, 0, nums.size() - 1);
    for(int i = 0; i < nums.size(); i+=2){
        max += nums[i];
    }

    return max; 
}

void quickSort(std::vector<int>& nums, int start, int end){
    if(start >= end) return;
    int pivot = nums[start];
    int left  = start;
    int right = end;
    while(left < right){
        while(left < right && nums[right] >= pivot){
            --right;
        }
        nums[left] = nums[right]; 
        while(left < right && nums[left] < pivot){
            ++left;
        }
        nums[right] = nums[left];
    }
    nums[left] = pivot;
    quickSort(nums, start, left - 1);
    quickSort(nums, left + 1, end);
}