/*
最长回文子串
给你一个字符串 s，找到 s 中最长的 回文 子串。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/array-and-string/conm7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include<iostream>
std::string longestPalindrome(std::string s);

int main(){
    std::string str = longestPalindrome("babaddtattarrattatddetartrateedredividerb");
    std::cout << str << std::endl;
}

std::string longestPalindrome(std::string s) {
    if(s.length() <= 1){
        return s;
    }
    std::string str;
    for(int i = 1; i < s.length(); ++i){
        int left = i - 1, right = i + 1;
        while(left >=0 && right <= s.length() && (s[left] == s[right])){
            --left;
            ++right;
        }
        if(str.length() < right - left - 1){
            str = s.substr(left+1, right - left - 1);
        }
        left = i - 1, right = i;
        while(left >=0 && right <= s.length() && (s[left] == s[right])){
            --left;
            ++right;
        }
        if(str.length() < right - left - 1){
            str = s.substr(left+1, right - left - 1);
        }
    }
    return str;
}