/*
从中序与后序遍历序列构造二叉树
给定两个整数数组 inorder 和 postorder ，其中 inorder 是二叉树的中序遍历， postorder 是同一棵树的后序遍历，请你构造并返回这颗 二叉树 。

示例 1:
输入：inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
输出：[3,9,20,null,null,15,7]

示例 2:
输入：inorder = [-1], postorder = [-1]
输出：[-1]

提示:
1 <= inorder.length <= 3000
postorder.length == inorder.length
-3000 <= inorder[i], postorder[i] <= 3000
inorder 和 postorder 都由 不同 的值组成
postorder 中每一个值都在 inorder 中
inorder 保证是树的中序遍历
postorder 保证是树的后序遍历

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/data-structure-binary-tree/xo98qt/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <vector>

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
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) // inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
    {
        // 1、后续数组postorder大小为0
        if (postorder.size() == 0) return NULL;

        // 2、后续数组postorder最后一个节点为当前根节点
        int rootVal = postorder[postorder.size() - 1];
        int rootIndex = -1;
        TreeNode* root = new TreeNode(rootVal);
        if (postorder.size() == 1) return root;

        // 3、寻找中序数组位置为切割点
        for (int i=0; i<inorder.size(); ++i)
        {
            if (inorder[i] == rootVal)
            {
                rootIndex = i;
                break;
            }
        }
        if (rootIndex < 0) return nullptr;

        // 4、切割中序数组 得到左中序数组、右中序数组
        int letfInSta  = 0, letfInEnd  = rootIndex; // 左中序
        std::vector<int> leftIn(inorder.begin() + letfInSta,  inorder.begin() + letfInEnd); // leftIn:[9]

        int rightInSta = rootIndex + 1, rightInEnd = inorder.size(); // 右中序
        std::vector<int> rightIn(inorder.begin() + rightInSta, inorder.begin() + rightInEnd); // rightIn:[15 20 7]

        // 5、切割后序数组 得到左后序数组、右后序数组
        int leftPosSta = 0, leftPosEnd = leftIn.size(); // 0-1
        std::vector<int> leftPos(postorder.begin() + leftPosSta,  postorder.begin() + leftPosEnd); // leftPos:[9]

        int rightPosSta = leftIn.size(), rightPosEnd = postorder.size() - 1;
        std::vector<int> rightPos(postorder.begin() + rightPosSta, postorder.begin() + rightPosEnd); // rightPos:[15 7 20]

        // 6、递归处理左区间和右区间
        root->left = buildTree(leftIn,  leftPos);
        root->right = buildTree(rightIn, rightPos);
        return root;
    }
};