/*
删除二叉搜索树中的节点
给定一个二叉搜索树的根节点 root 和一个值 key，删除二叉搜索树中的 key 对应的节点，并保证二叉搜索树的性质不变。返回二叉搜索树（有可能被更新）的根节点的引用。

一般来说，删除节点可分为两个步骤：

首先找到需要删除的节点；
如果找到了，删除它。
 
示例 1:
输入：root = [5,3,6,2,4,null,7], key = 3
输出：[5,4,6,2,null,null,7]
解释：给定需要删除的节点值是 3，所以我们首先找到 3 这个节点，然后删除它。
一个正确的答案是 [5,4,6,2,null,null,7], 如下图所示。
另一个正确答案是 [5,2,6,null,4,null,7]。

示例 2:
输入: root = [5,3,6,2,4,null,7], key = 0
输出: [5,3,6,2,4,null,7]
解释: 二叉树不包含值为 0 的节点

示例 3:
输入: root = [], key = 0
输出: []

提示:
节点数的范围 [0, 104].
-105 <= Node.val <= 105
节点值唯一
root 是合法的二叉搜索树
-105 <= key <= 105

进阶： 要求算法时间复杂度为 O(h)，h 为树的高度。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/introduction-to-data-structure-binary-search-tree/xpcnds/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

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
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (root == nullptr) return nullptr;
        if (root->val == key)
        {
            if (root->left == nullptr && root->right == nullptr) return nullptr;
            if (root->left == nullptr)
            {
                TreeNode* cur = root->right;
                delete root;
                return cur;
            } 
            if (root->right == nullptr)
            {
                TreeNode* cur = root->left;
                delete root;
                return cur;
            } 
            TreeNode* tmp = root->right;
            while (tmp->left != nullptr)
            {
                tmp = tmp->left;
            }
            tmp->left = root->left;
            TreeNode* cur = root->right;
            delete root;
            return cur;
        }
        root->left  = deleteNode(root->left,  key);
        root->right = deleteNode(root->right, key);
        return root;
    }
};