/*
删除排序数组中的重复项
给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。

考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：

更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
返回 k 。
判题标准:

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/cq376/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>

int removeDuplicates(std::vector<int>& nums);

int main(){
    std::vector<int> nums = {1, 1};
    int num = removeDuplicates(nums);
    for(int i = 0; i < nums.size(); ++i){
        std::cout << nums[i] << "\t";
    }
    std::cout << "\n" << num;
}

int removeDuplicates(std::vector<int>& nums){
    if(nums.size() == 1) return 1;
    int begin = 0;
    int end   = nums.size() - 1;
    int cur   = 1;
    while(cur <= end){
        while(cur <= end && nums[cur] > nums[begin]){
            ++ begin;
            ++ cur;
        }
        while(cur <= end && nums[cur] <= nums[begin]){
            ++ cur;
        }
        if(cur <= end){
            nums[++begin] = nums[cur];
        }
    }
    return begin + 1;
}