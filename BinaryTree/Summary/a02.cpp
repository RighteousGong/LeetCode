/*
从前序与中序遍历序列构造二叉树
给定两个整数数组 preorder 和 inorder ，其中 preorder 是二叉树的先序遍历， inorder 是同一棵树的中序遍历，请构造二叉树并返回其根节点。

示例 1:
输入: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
输出: [3,9,20,null,null,15,7]

示例 2:
输入: preorder = [-1], inorder = [-1]
输出: [-1]

提示:
1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder 和 inorder 均 无重复 元素
inorder 均出现在 preorder
preorder 保证 为二叉树的前序遍历序列
inorder 保证 为二叉树的中序遍历序列

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/data-structure-binary-tree/xoei3r/
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
    TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) 
    {
        // 1、前续数组preorder大小为0
        if (preorder.size() == 0) return NULL;

        // 2、前续数组preorder最后一个节点为当前根节点
        int rootVal = preorder[0];
        TreeNode* root = new TreeNode(rootVal);
        if (preorder.size() == 1) return root;

        // 3、寻找中序数组位置为切割点
        int rootIndex = 0;
        for (; rootIndex<inorder.size(); ++rootIndex)
        {
            if (inorder[rootIndex] == rootVal) break;
        }

        // 4、切割中序数组 得到左中序数组、右中序数组  左闭右开
        std::vector<int> leftIn(inorder.begin(), inorder.begin() + rootIndex);
        std::vector<int> rightIn(inorder.begin() + rootIndex + 1, inorder.end());

        // 5、切割前序数组 得到左前序数组、右前序数组
        std::vector<int> leftPre(preorder.begin() + 1, preorder.begin() + rootIndex + 1);
        std::vector<int> rightPre(preorder.begin() + rootIndex+1, preorder.end());

        // 6、递归处理左区间和右区间
        root->left  = buildTree(leftPre, leftIn);
        root->right = buildTree(rightPre, rightIn);
        return root;
    }
};
