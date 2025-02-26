/*
现二叉树的序列化与反序列化。这里不限定你的序列 / 反序列化算法执行逻辑，你只需要保证一个二叉树可以被序列化为一个字符串并且将这个字符串反序列化为原始的树结构。
提示: 输入输出格式与 LeetCode 目前使用的方式一致，详情请参阅 LeetCode 序列化二叉树的格式。你并非必须采取这种方式，你也可以采用其他的方法解决这个问题。

示例 1：
输入：root = [1,2,3,null,null,4,5]
输出：[1,2,3,null,null,4,5]

示例 2：
输入：root = []
输出：[]

示例 3：
输入：root = [1]
输出：[1]

示例 4：
输入：root = [1,2]
输出：[1,2]
 
提示：
树中结点数在范围 [0, 104] 内
-1000 <= Node.val <= 1000

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/data-structure-binary-tree/xomr73/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <string>
#include <queue>
#include <sstream>

struct TreeNode 
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
    int index = 0;
public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) 
    {
        if (root == nullptr) return "";
        std::queue<TreeNode* > qu;
        qu.emplace(root);
        std::string str;
        str.append(std::to_string(root->val) + "/");
        while (!qu.empty())
        {
            TreeNode* node = qu.front();
            qu.pop();
            if (node->left != nullptr)
            {
                str.append(std::to_string(node->left->val) + "/");
                qu.emplace(node->left);
            }
            else
            {
                str.append("null/");
            }
            if (node->right != nullptr)
            {
                str.append(std::to_string(node->right->val) + "/");
                qu.emplace(node->right);
            }
            else
            {
                str.append("null/");
            }
        }
        return str;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) 
    {
        if (data == "") return nullptr;
        std::stringstream ss(data);
        std::string item;
        std::vector<int> result;

        while (std::getline(ss, item, '/')) 
        {
            if (item != "null")
            {
                result.emplace_back(strToInt(item));
            }
            else
            {
                result.emplace_back(-1001);
            }
        }

        std::queue<TreeNode*> qu; 
        TreeNode* root = new TreeNode(result[0]);
        qu.emplace(root);
        int index = 1;
        while (index < result.size())
        {
            TreeNode* node = qu.front();
            qu.pop();
            if (index < result.size() && result[index] != -1001)
            {
                node->left = new TreeNode(result[index]);
                qu.emplace(node->left);
            }
            ++ index;
            if (index < result.size() && result[index] != -1001)
            {
                node->right = new TreeNode(result[index]);
                qu.emplace(node->right);
            }
            ++ index;
        }
        
        return root;
    }

    int strToInt(std::string data)
    {
        int sum = 0;
        if (data[0] == '-')
        {
            for (int i=1; i<data.size(); ++i)
            {
                sum = sum*10 + data[i] - 48;
            }
            return -sum;
        }
        for (auto i : data)
        {
            sum = sum*10 + i - 48;
        }
        return sum;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));