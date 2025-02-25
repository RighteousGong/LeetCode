/*
二叉树的前序遍历
给你二叉树的根节点 root ，返回它节点值的 前序 遍历。

示例 1：
输入：root = [1,null,2,3]
输出：[1,2,3]

示例 2：
输入：root = [1,2,3,4,5,null,8,null,null,6,7,9]
输出：[1,2,4,5,6,7,3,8,9]

示例 3：
输入：root = []
输出：[]

示例 4：
输入：root = [1]
输出：[1]

提示：
树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100
 
进阶：递归算法很简单，你可以通过迭代算法完成吗？

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/data-structure-binary-tree/xeywh5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <vector>
#include <stack>

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
    std::vector<int> preorderTraversal(TreeNode* root) 
    {
        std::vector<int> vec;
        std::stack<TreeNode*> nodes;
        TreeNode* currunt = root;
        while (currunt != nullptr || !nodes.empty())
        {
            while (currunt != nullptr)
            {
                vec.emplace_back(currunt->val);
                nodes.emplace(currunt);
                currunt = currunt->left;
            }

            currunt = nodes.top();
            nodes.pop();
            currunt = currunt->right;
        }
        return vec;
    }
};