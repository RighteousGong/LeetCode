/*
旋转矩阵

给你一幅由 N × N 矩阵表示的图像，其中每个像素的大小为 4 字节。请你设计一种算法，将图像旋转 90 度。
不占用额外内存空间能否做到？

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/clpgd/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <vector>
#include <iostream>

void rotate(std::vector<std::vector<int>>& matrix);

int main(){
    std::vector<std::vector<int>> matrix = {{5, 1, 9,11},{2, 4, 8,10},{13, 3, 6, 7},{15,14,12,16}};
    rotate(matrix);
    for(int i = 0; i < matrix.size(); ++ i){
        for (int j = 0; j < matrix[0].size(); ++j){
            std::cout << matrix[i][j] << " ";
        }
        std::cout<< std::endl;
    }
}

void rotate(std::vector<std::vector<int>>& matrix){
    for(int i = 0; i < matrix.size(); ++ i){
        for (int j = 0; j < matrix.size() - i - 1; ++j){
            matrix[i][j] = matrix[matrix.size() - j - 1][matrix.size() - i - 1] + matrix[i][j];
            matrix[matrix.size() - j - 1][matrix.size() - i - 1] = matrix[i][j] - matrix[matrix.size() - j - 1][matrix.size() - i - 1];
            matrix[i][j] =  matrix[i][j] - matrix[matrix.size() - j - 1][matrix.size() - i - 1];
        }
    }
    for(int i = 0; i < matrix.size() / 2; ++ i){
        for (int j = 0; j < matrix.size(); ++j){
            matrix[i][j] = matrix[matrix.size() - i - 1][j] + matrix[i][j];
            matrix[matrix.size() - i - 1][j] = matrix[i][j] - matrix[matrix.size() - i - 1][j];
            matrix[i][j] =  matrix[i][j] - matrix[matrix.size() - i - 1][j];
        }
    }
}