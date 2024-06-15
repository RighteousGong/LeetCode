/*
移动零
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。

进阶：你能尽量减少完成的操作次数吗？

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/c6u02/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
void moveZeroes(std::vector<int>& nums);

int main(){
    std::vector<int> nums = {0,1,0,3,12};
    moveZeroes(nums);
    for(int i:nums){
        std::cout << i << "\t";
    }
}

void moveZeroes(std::vector<int>& nums){
    int size = nums.size();
    if(size <= 1) return;
    int fast = 0;
    int slow = 0;
    while(fast < size){
        while(slow < size && nums[slow] != 0){
            ++slow;
            ++fast;
        }
        while(fast < size && nums[fast] == 0){
            ++fast;
        }
        if(fast < size){
            nums[slow] = nums[fast];
            nums[fast] = 0;
        }
    }
}