/*
最大连续1的个数
给定一个二进制数组 nums ， 计算其中最大连续 1 的个数。


作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/cd71t/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>

int findMaxConsecutiveOnes(std::vector<int>& nums);

int main(){
    std::vector<int> nums = {1,1,0,1,1,1};
    int count = findMaxConsecutiveOnes(nums);
    std::cout << count << std::endl;
}

int findMaxConsecutiveOnes(std::vector<int>& nums) {
    int count = 0;
    int i = 0;
    int size = nums.size();
    while(i < size){
        if(nums[i] == 1){
            int j = i + 1;
            while(j < size && nums[j] == 1){
                ++ j;
            }
            if(j - i > count){
                count = j - i;
            }
            i = ++j;
        }else
            ++ i;
    }
    return count;
}