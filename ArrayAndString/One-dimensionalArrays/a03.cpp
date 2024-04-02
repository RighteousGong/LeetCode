/*
合并区间
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。
请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/c5tv3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals);

int main(){
    std::vector<std::vector<int>> nums = {{1,3}, {2,6}, {8,10}, {15,18}};
    std::vector<std::vector<int>> index = merge(nums);
    for (size_t i = 0; i < index.size(); i++){
        std::cout << index[i][0] << "," << index[i][1] << "   ";   
    }
}

std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> newIntervals;
    newIntervals.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); i++){
        if(intervals[i][0] <= newIntervals.back()[1]){
            newIntervals.back()[1] = std::max(newIntervals.back()[1], intervals[i][1]);
        }else{
            newIntervals.push_back(intervals[i]);
        }
    }
    return newIntervals;
}