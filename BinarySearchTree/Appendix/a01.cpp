/*
平衡二叉树
给定一个二叉树，判断它是否是 平衡二叉树  

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：true

示例 2：
输入：root = [1,2,2,3,3,null,null,4,4]
输出：false

示例 3：
输入：root = []
输出：true

提示：

树中的节点数在范围 [0, 5000] 内
-104 <= Node.val <= 104

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/introduction-to-data-structure-binary-search-tree/xmx4r7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <cmath>

struct TreeNode 
{
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
    bool isBalanced(TreeNode* root)
    {
        int deep = nextNode(root, 0);
        if (deep == -1) return false;
        return true;
    }

    int nextNode(TreeNode* node, int high)
    {
        if (node == nullptr)
        {
            return high;
        }
        int left  = nextNode(node->left,  high+1);
        if (left == -1) return -1;
        int right = nextNode(node->right, high+1);
        if (right == -1) return -1;
        if (std::abs(left - right) > 1) return -1;
        return left > right ? left : right;
    }
};