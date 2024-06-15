/*
两数之和 II - 输入有序数组
给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 target 的两个数。如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。

以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。

你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。

你所设计的解决方案必须只使用常量级的额外空间。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/cnkjg/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>

std::vector<int> twoSum(std::vector<int>& numbers, int target);

int main(){
    std::vector<int> numbers = {2,7,11,15};
    std::vector<int> result = twoSum(numbers, 9);
    for(int i:result){
        std::cout << i << " ";
    }
}

std::vector<int> twoSum(std::vector<int>& numbers, int target){
    int i = 0;
    int j = numbers.size() - 1;
    while(i < j){
        if(numbers[i] + numbers[j] < target) ++i;
        if(numbers[i] + numbers[j] > target) --j;
        if(numbers[i] + numbers[j] == target) return std::vector<int>{i + 1, j + 1};
    }
    return std::vector<int>{-1, -1};
}