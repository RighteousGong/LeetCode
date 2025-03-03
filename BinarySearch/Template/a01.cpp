/*
x 的平方根
给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。

示例 1：
输入：x = 4
输出：2

示例 2：
输入：x = 8
输出：2
解释：8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/binary-search/xe9cog/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
class Solution
{
public:
    int mySqrt(int x)
    {
        if (x == 0 || x == 1) return x;
        int left = 0, right = x, mid = 0, ans = 0;
        while (left <= right)
        {
            int mid = left + (right  - left)/2;
            if (mid <= x / mid)
            {
                left = mid+1;
                ans = mid;
            }
            if (mid > x / mid)  right = mid-1;
        }
        return ans;
    }
};