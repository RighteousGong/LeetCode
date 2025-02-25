/*
二叉树的最大深度
给定一个二叉树 root ，返回其最大深度。

二叉树的 最大深度 是指从根节点到最远叶子节点的最长路径上的节点数。

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：3

示例 2：
输入：root = [1,null,2]
输出：2

提示：

树中节点的数量在 [0, 104] 区间内。
-100 <= Node.val <= 100

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/data-structure-binary-tree/xoh1zg/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution 
{
public:
    int maxDepth(TreeNode* root) 
    {
        if (root == nullptr) return 0;

        int high = getDeep(root, 0);
        return high;
    }

    int getDeep(TreeNode* root, int high)
    {
        if (root == nullptr)
        {
            return high;
        }
        ++ high;
        int tmp = high;
        high = getDeep(root->left, tmp);
        high = std::max(getDeep(root->right, tmp), high);
        return high;
    }
};