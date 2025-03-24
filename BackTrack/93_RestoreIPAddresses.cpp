/*
93. 复原 IP 地址
中等
有效 IP 地址 正好由四个整数（每个整数位于 0 到 255 之间组成，且不能含有前导 0），整数之间用 '.' 分隔。

例如："0.1.2.201" 和 "192.168.1.1" 是 有效 IP 地址，但是 "0.011.255.245"、"192.168.1.312" 和 "192.168@1.1" 是 无效 IP 地址。
给定一个只包含数字的字符串 s ，用以表示一个 IP 地址，返回所有可能的有效 IP 地址，这些地址可以通过在 s 中插入 '.' 来形成。你 不能 重新排序或删除 s 中的任何数字。你可以按 任何 顺序返回答案。

示例 1：
输入：s = "25525511135"
输出：["255.255.11.135","255.255.111.35"]

示例 2：
输入：s = "0000"
输出：["0.0.0.0"]

示例 3：
输入：s = "101023"
输出：["1.0.10.23","1.0.102.3","10.1.0.23","10.10.2.3","101.0.2.3"]

提示：
1 <= s.length <= 20
s 仅由数字组成
*/
#include <vector>
#include <iostream>
#include <string>

class Solution
{
	std::vector<std::string> result;
public:
	std::vector<std::string> restoreIpAddresses(std::string s)
	{
		backTracking(0, s, "");
		return result;
	}

	void backTracking(int count, std::string s, std::string resStr)
	{
		if (count == 4 && s.size() == 0)
		{
			result.emplace_back(resStr.substr(0, resStr.size() - 1));
			return;
		}
		if (count > 3)
			return;
		for (int i = 1; i <= 3 && i <= s.size(); ++i)
		{
			std::string tmp = s.substr(0, i);
			if (tmp.size() > 1 && tmp[0] == '0') continue;
			if (tmp.size() == 3)
			{
				int g = tmp[2] - '0';
				int s = tmp[1] - '0';
				int b = tmp[0] - '0';
				if (g + 10 * s + 100 * b > 255)
					continue;
			}
			resStr += tmp;
			resStr += ".";
			backTracking(count + 1, s.substr(i), resStr);
			resStr.erase(resStr.size() - (i + 1));
		}
	}
};