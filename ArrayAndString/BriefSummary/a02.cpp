/*
杨辉三角 II
给定一个非负索引 rowIndex，返回「杨辉三角」的第 rowIndex 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。

进阶：

你可以优化你的算法到 O(rowIndex) 空间复杂度吗？

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/ctyt1/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>

std::vector<int> getRow(int rowIndex);

int main(){
    std::vector<int> result = getRow(9);
    for(int i:result){
        std::cout << i << "\t";
    }
}

std::vector<int> getRow(int rowIndex){
    if(rowIndex < 0) return std::vector<int>{};
    std::vector<int> result(rowIndex + 1, 0);
    result[0] = 1;
    for(int i = 1; i <= rowIndex; ++i){
        for(int j = i; j > 0; --j){
            result[j] = result[j - 1] + result[j];
        }
    }
    return result;
}