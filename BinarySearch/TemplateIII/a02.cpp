/*
找到 K 个最接近的元素
给定一个 排序好 的数组 arr ，两个整数 k 和 x ，从数组中找到最靠近 x（两数之差最小）的 k 个数。返回的结果必须要是按升序排好的。

整数 a 比整数 b 更接近 x 需要满足：

|a - x| < |b - x| 或者
|a - x| == |b - x| 且 a < b

示例 1：
输入：arr = [1,2,3,4,5], k = 4, x = 3
输出：[1,2,3,4]

示例 2：
输入：arr = [1,1,2,3,4,5], k = 4, x = -1
输出：[1,1,2,3]

提示：
1 <= k <= arr.length
1 <= arr.length <= 104
arr 按 升序 排列
-104 <= arr[i], x <= 104

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/binary-search/xeve4m/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <vector>
#include <cmath>

class Solution {
public:
    std::vector<int> findClosestElements(std::vector<int>& arr, int k, int x) {
        int left=0,right=arr.size()-k,mid=0;
        // 直接寻找最左侧索引
        while(left<right){
            mid=left+(right-left)/2;
            if(x-arr[mid]>arr[mid+k]-x){
                left=mid+1;
            }else{
                right=mid;
            }
        }
        return std::vector<int>(arr.begin() + left, arr.begin() + left + k);
    }
};
