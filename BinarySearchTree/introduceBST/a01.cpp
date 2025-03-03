/*
验证二叉搜索树
给你一个二叉树的根节点 root ，判断其是否是一个有效的二叉搜索树。

有效 二叉搜索树定义如下：
节点的左子树只包含 小于 当前节点的数。
节点的右子树只包含 大于 当前节点的数。
所有左子树和右子树自身必须也是二叉搜索树。
 
示例 1：
输入：root = [2,1,3]
输出：true

示例 2：
输入：root = [5,1,4,null,null,3,6]
输出：false
解释：根节点的值是 5 ，但是右子节点的值是 4 。
 
提示：
树中节点数目范围在[1, 104] 内
-231 <= Node.val <= 231 - 1

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/introduction-to-data-structure-binary-search-tree/xpkc6i/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <vector>
#include <stack>

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
    bool isValidBST(TreeNode* root)
    {
        std::vector<int> result;
        std::stack<TreeNode*> st;
        TreeNode* node = root;
        while (node != nullptr || !st.empty())
        {
            while (node != nullptr)
            {
                st.emplace(node);
                node = node->left;
            }

            node = st.top();
            st.pop();
            result.emplace_back(node->val);
            
            node = node->right;
        }

        for (int i=1; i<result.size(); ++i)
        {
            if(result[i] <= result[i-1])
            {
                return false;
            }
        }
        return true;
    }
};