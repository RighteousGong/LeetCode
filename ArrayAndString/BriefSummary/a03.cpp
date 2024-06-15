/*
反转字符串中的单词 III
给定一个字符串 s ，你需要反转字符串中每个单词的字符顺序，同时仍保留空格和单词的初始顺序。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/c8su7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>
#include <string>

std::string reverseWords(std::string s);

int main(){
    std::string str = "Let's take LeetCode contest";
    std::cout << reverseWords(str);
}

std::string reverseWords(std::string s){
    std::string result(s.size(), ' ');
    std::cout << result << std::endl;
    int size = s.size();
    int num = 0;
    for(int i = size - 1; i >= 0; --i){
        int j = i;
        while(j >= 0 && s[j] != ' '){
            --j;
            ++num;
        }
        while(num > 0){
            --num;
            result[i--] = s[++j];
        }
        if( i >= 0) result[i] = s[i];
    }
    return result;
}