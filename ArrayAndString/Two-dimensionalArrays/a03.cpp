/*
对角线遍历
给你一个大小为 m x n 的矩阵 mat ，请以对角线遍历的顺序，用一个数组返回这个矩阵中的所有元素。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/cuxq3/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <vector>
#include <iostream>

std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& mat);

int main(){
    std::vector<std::vector<int>> matrix = {{3},{2}};
    std::vector<int> out = findDiagonalOrder(matrix);
    for(int i = 0; i < out.size(); ++ i){
        std::cout << out[i] << " ";
    }
}

std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    std::vector<int> out;
    for(int count = 0; count < m + n; ++ count){
        if(count %2 == 1){
            for(int i = 0, j = count - i; i < m && j >= 0; ++i, -- j){
                if((i + j) == count && j < n){
                    out.push_back(mat[i][j]);
                }
            }
        }else{
            for(int j = 0, i = count - j; j < n && i >= 0; ++j, -- i){
                if((i + j) == count && i < m){
                    out.push_back(mat[i][j]);
                }
            }
        }
    }
    return out;
}