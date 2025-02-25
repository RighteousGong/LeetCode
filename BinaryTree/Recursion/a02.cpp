/*
对称二叉树
给你一个二叉树的根节点 root ， 检查它是否轴对称。

示例 1：
输入：root = [1,2,2,3,4,4,3]
输出：true

示例 2：
输入：root = [1,2,2,null,3,null,3]
输出：false

提示：
树中节点数目在范围 [1, 1000] 内
-100 <= Node.val <= 100

进阶：你可以运用递归和迭代两种方法解决这个问题吗？

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/data-structure-binary-tree/xoxzgv/
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
    bool isSymmetric(TreeNode* root) 
    {
        if (root == nullptr) return false;    
        return comparedNode(root->left, root->right);
    }

    bool comparedNode(TreeNode* n1, TreeNode* n2)
    {
        if (n1 == nullptr && n2 ==nullptr) return true;
        if (n1 == nullptr  ||  n2 == nullptr) return false;
        if (n1->val != n2->val) return false;
        return comparedNode(n1->left, n2->right) && comparedNode(n1->right, n2->left);
    }
};