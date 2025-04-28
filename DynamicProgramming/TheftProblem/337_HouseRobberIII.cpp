/*
337. 打家劫舍 III
中等
小偷又发现了一个新的可行窃的地区。这个地区只有一个入口，我们称之为 root 。
除了 root 之外，每栋房子有且只有一个“父“房子与之相连。一番侦察之后，聪明的小偷意识到“这个地方的所有房屋的排列类似于一棵二叉树”。 如果 两个直接相连的房子在同一天晚上被打劫 ，房屋将自动报警。
给定二叉树的 root 。返回 在不触动警报的情况下 ，小偷能够盗取的最高金额 。

 
示例 1:
输入: root = [3,2,3,null,3,null,1]
输出: 7 
解释: 小偷一晚能够盗取的最高金额 3 + 3 + 1 = 7

示例 2:
输入: root = [3,4,5,1,3,null,1]
输出: 9
解释: 小偷一晚能够盗取的最高金额 4 + 5 = 9
 
提示：
树的节点数在 [1, 104] 范围内
0 <= Node.val <= 104
*/
#include <vector>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 卡在122 / 124 个通过的测试用例，超时，逻辑应该没问题
class Solution
{
public:
    int rob(TreeNode* root)
    {
        if (root == nullptr) return 0;
        return std::max(getValue(root, true), getValue(root, false));
    }

    int getValue(TreeNode* root, bool isTheft)
    {
        int left = 0;
        int right = 0;
        if (root->left != nullptr)
        {
            left = getValue(root->left, !isTheft);
            if (!isTheft)
                left = std::max(left, getValue(root->left, false)); // 这里重复遍历了后面节点
        }
        if (root->right != nullptr)
        {
            right = getValue(root->right, !isTheft);
            if (!isTheft)
                right = std::max(right, getValue(root->right, false)); // 这里重复遍历了后面节点
        }
        int sum = left + right;
        if (isTheft)
            sum += root->val;
        return sum;
    }
};

// 动态规划：遍历过程中同时储存偷和不偷的值，避免重复遍历
class Solution
{
public:
    int rob(TreeNode* root)
    {
        if (root == nullptr) return 0;
        std::vector<int> dp = getValue(root);
        return std::max(dp[0], dp[1]);
    }

    std::vector<int> getValue(TreeNode* root)
    {
        std::vector<int> dp(2, 0);
        if (root == nullptr) return dp;

        std::vector<int> left  = getValue(root->left);
        std::vector<int> right = getValue(root->right);
        dp[1] = root->val + left[0] + right[0]; // 偷当前节点
        dp[0] = std::max(left[0], left[1]) + std::max(right[0], right[1]); // 不偷当前节点
        return dp;
    }
};