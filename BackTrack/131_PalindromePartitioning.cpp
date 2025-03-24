/*
131. 分割回文串
中等

给你一个字符串 s，请你将 s 分割成一些 子串，使每个子串都是 回文串 。返回 s 所有可能的分割方案。

示例 1：
输入：s = "aab"
输出：[["a","a","b"],["aa","b"]]

示例 2：
输入：s = "a"
输出：[["a"]]

提示：
1 <= s.length <= 16
s 仅由小写英文字母组成
*/
#include <vector>
#include <string>

class Solution
{
	std::vector<std::vector<std::string>> result;
	std::vector<std::string> path;
public:
	std::vector<std::vector<std::string>> partition(std::string s)
	{
		backTracking(s);
		return result;
	}

	void backTracking(std::string s)
	{
		if (s.size() == 0)
		{
			result.emplace_back(path);
			return;
		}
		for (int i = 1; i <= s.size(); ++i)
		{
			std::string tmp = s.substr(0, i);
			if (isPalindrome(tmp))
			{
				path.emplace_back(tmp);
				backTracking(s.substr(i));
				path.pop_back();
			}
		}
	}

	bool isPalindrome(std::string str)
	{
		if (str.size() == 0)
			return false;
		int left = 0;
		int right = str.size() - 1;
		while (left <= right)
		{
			if (str[left] != str[right])
				return false;
			++left, --right;
		}
		return true;
	}
};