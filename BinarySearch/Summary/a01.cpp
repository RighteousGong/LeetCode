/*
Pow(x, n)
实现 pow(x, n) ，即计算 x 的整数 n 次幂函数（即，xn ）。

示例 1：
输入：x = 2.00000, n = 10
输出：1024.00000

示例 2：
输入：x = 2.10000, n = 3
输出：9.26100

示例 3：
输入：x = 2.00000, n = -2
输出：0.25000
解释：2-2 = 1/22 = 1/4 = 0.25

提示：
-100.0 < x < 100.0
-231 <= n <= 231-1
n 是一个整数
要么 x 不为零，要么 n > 0 。
-104 <= xn <= 104

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/binary-search/xe7k32/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

class Solution
{
public:
	double myPow(double x, int n)
	{
		long long N = n;
		if (N < 0)
		{
			N = -N;
			x = 1 / x;
		}
		double result = 1.0;
		while (N > 0)
		{
			if (N % 2 == 1)
				result *= x;
			x *= x;
			N >>= 1;
		}
		return result;
	}
};