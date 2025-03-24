/*
17. 电话号码的字母组合
中等

给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。答案可以按 任意顺序 返回。
给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。

示例 1：
输入：digits = "23"
输出：["ad","ae","af","bd","be","bf","cd","ce","cf"]

示例 2：
输入：digits = ""
输出：[]

示例 3：
输入：digits = "2"
输出：["a","b","c"]

提示：
0 <= digits.length <= 4
digits[i] 是范围 ['2', '9'] 的一个数字。
*/
#include <vector>
#include <string>

class Solution 
{
	std::vector<std::string> result;
	std::vector<std::string> words;
public:
	std::vector<std::string> letterCombinations(std::string digits)
	{
		int size = digits.size();
		for (auto i : digits)
		{
			switch (i)
			{
			case '1':
				words.emplace_back();
				break;
			case '2':
				words.emplace_back("abc");
				break;
			case '3':
				words.emplace_back("def");
				break;
			case '4':
				words.emplace_back("ghi");
				break;
			case '5':
				words.emplace_back("jkl");
				break;
			case '6':
				words.emplace_back("mno");
				break;
			case '7':
				words.emplace_back("pqrs");
				break;
			case '8':
				words.emplace_back("tuv");
				break;
			case '9':
				words.emplace_back("wxyz");
				break;
			case '0':
				words.emplace_back("");
				break;
			default:
				break;
			}
		}
	}

	void backTracking(int size, std::string str)
	{
		if (str.size() == size)
		{
			result.emplace_back(str);
			return;
		}
		for (int i = 0; i < words[str.size()].size(); ++i)
		{
			str += words[str.size()][i];
			backTracking(size, str);
			str.pop_back();
		}
	}
};