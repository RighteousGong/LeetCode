/*
移除元素
给你一个数组 nums 和一个值 val，你需要 原地 移除所有数值等于 val 的元素。元素的顺序可能发生改变。然后返回 nums 中与 val 不同的元素的数量。

假设 nums 中不等于 val 的元素数量为 k，要通过此题，您需要执行以下操作：

更改 nums 数组，使 nums 的前 k 个元素包含不等于 val 的元素。nums 的其余元素和 nums 的大小并不重要。
返回 k。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/cwuyj/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
int removeElement(std::vector<int>& nums, int val);

int main(){
    std::vector<int> nums = {3, 2, 2, 3};
    int k = removeElement(nums, 2);
    for(int i = 0; i < k; ++ i){
        std::cout << nums[i] << " ";
    }
    std::cout << "\n" << k;
}

int removeElement(std::vector<int>& nums, int val){
    int fast = 0;
    int slow = 0;
    int size = nums.size();
    int k = 0;
    while(fast < size){
        if(nums[fast] != val){
            nums[slow] = nums[fast];
            ++slow;
            ++k;
        }
        ++fast;
    }
    return k;
}