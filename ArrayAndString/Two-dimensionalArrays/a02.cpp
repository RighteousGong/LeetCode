/*
零矩阵
编写一种算法，若M × N矩阵中某个元素为0，则将其所在的行与列清零。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/ciekh/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <vector>
#include <iostream>

void setZeroes(std::vector<std::vector<int>>& matrix);

int main(){
    std::vector<std::vector<int>> matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    setZeroes(matrix);
    for(int i = 0; i < matrix.size(); ++ i){
        for (int j = 0; j < matrix[0].size(); ++j){
            std::cout << matrix[i][j] << " ";
        }
        std::cout<< std::endl;
    }
}

/*
用int row[matrix.size()];int column[matrix[0].size()];的缺点
未初始化数组：C++中的局部数组row和column没有默认初始化值，可能包含随机垃圾值，这会导致不正确的结果。
数组的使用：如果矩阵的尺寸为零，这会导致数组定义错误。
代码不使用标准库的最佳实践：C++标准库提供的std::vector更安全，并且可以避免手动管理内存。
*/
void setZeroes(std::vector<std::vector<int>>& matrix) {
    std::vector<bool> row(matrix.size());
    std::vector<bool> column(matrix[0].size());
    for(int i = 0; i < matrix.size(); ++ i){
        for (int j = 0; j < matrix[0].size(); ++ j){
            if (matrix[i][j] == 0){
                row[i] = true;
                column[j] = true;
            }
        }
    }
    for(int i = 0; i < matrix.size(); ++ i){
        for (int j = 0; j < matrix[0].size(); ++ j){
            if (row[i] || column[j]){
                matrix[i][j] = 0;
            }
        }
    }
}