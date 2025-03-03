/*
猜数字大小
我们正在玩猜数字游戏。猜数字游戏的规则如下：

我会从 1 到 n 随机选择一个数字。 请你猜选出的是哪个数字。

如果你猜错了，我会告诉你，我选出的数字比你猜测的数字大了还是小了。

你可以通过调用一个预先定义好的接口 int guess(int num) 来获取猜测结果，返回值一共有三种可能的情况：

-1：你猜的数字比我选出的数字大 （即 num > pick）。
1：你猜的数字比我选出的数字小 （即 num < pick）。
0：你猜的数字与我选出的数字相等。（即 num == pick）。
返回我选出的数字。

示例 1：
输入：n = 10, pick = 6
输出：6

示例 2：
输入：n = 1, pick = 1
输出：1

示例 3：
输入：n = 2, pick = 1
输出：1

提示：
1 <= n <= 231 - 1
1 <= pick <= n

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/binary-search/xee4ev/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
class Solution
{
public:
    int guessNumber(int n)
    {
        int l = 0, r = n;
        while (l <= r)
        {
            int mid = l + (r-l)/2;
            int res = guess(mid);  // 系统提供的 API
            if (res == 1) r = mid - 1;
            else if (res == -1) l = mid + 1;
            else return mid;
        }
        return -1;
    }
};