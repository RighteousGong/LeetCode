/*
有效的完全平方数
给你一个正整数 num 。如果 num 是一个完全平方数，则返回 true ，否则返回 false 。

完全平方数 是一个可以写成某个整数的平方的整数。换句话说，它可以写成某个整数和自身的乘积。

不能使用任何内置的库函数，如  sqrt 。
 
示例 1：
输入：num = 16
输出：true
解释：返回 true ，因为 4 * 4 = 16 且 4 是一个整数。

示例 2：
输入：num = 14
输出：false
解释：返回 false ，因为 3.742 * 3.742 = 14 但 3.742 不是一个整数。
 
提示：
1 <= num <= 231 - 1

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/binary-search/xel3tc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution
{
public:
	bool isPerfectSquare(int num)
	{
		int left = 0, right = num;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (mid * mid > num)
			{
				right = mid - 1;
			}
			else if(mid * mid < num)
			{
				left = mid + 1;
			}
			else
			{
				return true;
			}
		}
		return false;
	}
};