/*
长度最小的子数组
给定一个含有 n 个正整数的数组和一个正整数 target 。

找出该数组中满足其总和大于等于 target 的长度最小的 子数组 [numsl, numsl+1, ..., numsr-1, numsr] ，并返回其长度。如果不存在符合条件的子数组，返回 0 。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/c0w4r/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>

int minSubArrayLen(int target, std::vector<int>& nums);

int main(){
    std::vector<int> nums = {1, 2, 3, 4, 5};
    std::cout << minSubArrayLen(11, nums);
}

int minSubArrayLen(int target, std::vector<int>& nums){
    int i = 0;
    int size = nums.size();
    int count = size + 1;
    while(i < size){
        if(nums[i] >= target) return 1;
        int j = i + 1;
        int num = nums[i];
        while(j < size){
            while(j < size && num < target){
                num += nums[j];
                ++j;
            }
            if(num < target){
                return count == size + 1 ? 0 : count;
            }
            if(num >= target){
                count = count > (j - i) ? (j - i) : count;
                break;
            }
        }
        ++i;
    }
    return count == size + 1 ? 0 : count;
}