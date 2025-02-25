/*

给你二叉树的根节点 root ，返回其节点值的 层序遍历 。 （即逐层地，从左到右访问所有节点）。

示例 1：
输入：root = [3,9,20,null,null,15,7]
输出：[[3],[9,20],[15,7]]

示例 2：
输入：root = [1]
输出：[[1]]

示例 3：
输入：root = []
输出：[]
 
提示：

树中节点数目在范围 [0, 2000] 内
-1000 <= Node.val <= 1000

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/data-structure-binary-tree/xefh1i/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <vector>
#include <queue>

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
    std::vector<std::vector<int>> levelOrder(TreeNode* root) 
    {
        std::vector<std::vector<int>> vec;
        std::queue<TreeNode*> qe;
        int size = 0;
        if (root != nullptr)
        {
            qe.emplace(root);
            size = 1;
        }
        while (!qe.empty())
        {
            int temp = size;
            size = 0;
            std::vector<int> tmpVec;
            for (int i=0; i<temp; ++i)
            {
                TreeNode* node = qe.front();
                tmpVec.push_back(node->val);
                qe.pop();
                if (node->left != nullptr)
                {
                    ++size;
                    qe.emplace(node->left);
                }
                if (node->right != nullptr)
                {
                    ++size;
                    qe.emplace(node->right);
                }
            }   
            vec.push_back(tmpVec);
        }
        return vec;
    }
};