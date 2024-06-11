/*
实现 strStr()
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/cm5e2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>

int* getnext(std::string str);
int strStr(std::string haystack, std::string needle);

int main(){
    std::string haystack = "sadbutsad", needle = "sad";
    std::cout << strStr(haystack, needle);
}

int strStr(std::string haystack, std::string needle){
    int nee_len = needle.length();
    int hay_len = haystack.length();
    if(nee_len > hay_len){
        return -1;
    }
    int* next = getnext(needle);
    int j = 0;
    for(int i = 0; i < hay_len; ++i){
        while(j > 0 && haystack[i] != needle[j]){
            j = next[j - 1];
        }
        if(haystack[i] == needle[j]){
            ++j;
        }
        if(j == nee_len){
            delete[] next;
            return i - nee_len + 1;
        }
    }
    delete[] next;
    return -1;
}

int* getnext(std::string str){
    int len = str.length();
    int* next = new int[len];
    next[0] = 0;
    int j = 0;
    for(int i = 1; i < len; ++i){
        while(j > 0 && str[i] != str[j]){
            j = next[j - 1];
        }
        if(str[i] == str[j]){
            ++j;
        }
        next[i] = j;
    }

    return next;
}