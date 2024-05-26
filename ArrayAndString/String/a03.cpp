/*
翻转字符串里的单词
给你一个字符串 s ，请你反转字符串中 单词 的顺序。

单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。

返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。

注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/crmp5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include<iostream>
std::string reverseWords(std::string s);

int main(){
    std::string str = reverseWords("the sky is blue");
    std::cout << str << std::endl;
}

std::string reverseWords(std::string s) {
    if(s.find(' ') > s.length()){
        return s;
    }
    bool addSpace = false;
    int len = s.length();
    for(int i = 0; i < len; ++i){
        int start = i;
        int j = i;
        while(s[j] != ' ' && j < len){
            addSpace = true;
            ++j;
            ++i;
        }
        if(addSpace){
            addSpace = false;
            s.insert(len, s.substr(start, j - start));
            s.insert(len, " ");
        }
    }
    return s.substr(len + 1, s.length());
}