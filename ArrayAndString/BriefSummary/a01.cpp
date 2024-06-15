/*
杨辉三角
给定一个非负整数 numRows，生成「杨辉三角」的前 numRows 行。

在「杨辉三角」中，每个数是它左上方和右上方的数的和。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/cuj3m/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>

std::vector<std::vector<int>> generate(int numRows);

int main(){
    std::vector<std::vector<int>> result = generate(6);
    for(std::vector<int> i:result){
        for(int j:i){
            std::cout << j << "\t";
        }
        std::cout << std::endl;
    }
}

std::vector<std::vector<int>> generate(int numRows){
    if(numRows < 0) return std::vector<std::vector<int>>{};
    std::vector<std::vector<int>> result;
    result.push_back(std::vector<int>{1});
    for(int i = 1; i < numRows; ++ i){
        std::vector<int> tmp(i+1);
        tmp[0] = 1;
        tmp[i] = 1;
        for(int j = 1; j < i; ++ j){
            tmp[j] = result[i - 1][j - 1] + result[i - 1][j];
        }
        result.push_back(tmp);
    }
    return result;
}