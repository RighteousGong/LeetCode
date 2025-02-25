/*
二叉树的后序遍历
给你一棵二叉树的根节点 root ，返回其节点值的 后序遍历 。

示例 1：
输入：root = [1,null,2,3]
输出：[3,2,1]
解释：


示例 2：
输入：root = [1,2,3,4,5,null,8,null,null,6,7,9]
输出：[4,6,7,5,2,9,8,3,1]
解释：

示例 3：
输入：root = []
输出：[]

示例 4：
输入：root = [1]
输出：[1]

提示：

树中节点的数目在范围 [0, 100] 内
-100 <= Node.val <= 100

进阶：递归算法很简单，你可以通过迭代算法完成吗？

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/data-structure-binary-tree/xebrb2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <vector>
#include <stack>
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
    std::vector<int> postorderTraversal(TreeNode* root) 
    {
        std::vector<int> vec;
        std::stack<TreeNode*>  st;
        if (root == nullptr)
            return vec;
        st.emplace(root);
        while (!st.empty())
        {
            TreeNode* node = st.top();
            st.pop();
            vec.emplace_back(node->val);
            if (node->left != nullptr)
            {
                st.emplace(node->left);
            }
            if (node->right != nullptr)
            {
                st.emplace(node->right);
            }
        }
        std::reverse(vec.begin(), vec.end());
        return vec;
    }
};