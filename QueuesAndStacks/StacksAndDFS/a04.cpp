/*
二叉树的中序遍历
给定一个二叉树的根节点 root ，返回 它的 中序 遍历 。

 

示例 1：
输入：root = [1,null,2,3]
输出：[1,3,2]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]
 

提示：

树中节点数目在范围 [0, 100] 内
-100 <= Node.val <= 100
 

进阶: 递归算法很简单，你可以通过迭代算法完成吗？

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/queue-stack/gnq5i/
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
    std::vector<int> inorderTraversal(TreeNode* root) 
    {
        std::vector<int> result;
        std::stack<TreeNode*> nodeStack;

        TreeNode* current = root;
        while (current!=nullptr || !nodeStack.empty())
        {
            while (current != nullptr)
            {
                nodeStack.emplace(current);
                current = current->left;
            }
            
            current = nodeStack.top();
            nodeStack.pop();
            result.emplace_back(current->val);

            current = current->right;
        }
        
        return result;
    }
};