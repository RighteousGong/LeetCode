/*
克隆图
给你无向 连通 图中一个节点的引用，请你返回该图的 深拷贝（克隆）。

图中的每个节点都包含它的值 val（int） 和其邻居的列表（list[Node]）。

class Node {
    public int val;
    public List<Node> neighbors;
}
 

测试用例格式：

简单起见，每个节点的值都和它的索引相同。例如，第一个节点值为 1（val = 1），第二个节点值为 2（val = 2），以此类推。该图在测试用例中使用邻接列表表示。

邻接列表 是用于表示有限图的无序列表的集合。每个列表都描述了图中节点的邻居集。

给定节点将始终是图中的第一个节点（值为 1）。你必须将 给定节点的拷贝 作为对克隆图的引用返回。

示例 1：
输入：adjList = [[2,4],[1,3],[2,4],[1,3]]
输出：[[2,4],[1,3],[2,4],[1,3]]
解释：
图中有 4 个节点。
节点 1 的值是 1，它有两个邻居：节点 2 和 4 。
节点 2 的值是 2，它有两个邻居：节点 1 和 3 。
节点 3 的值是 3，它有两个邻居：节点 2 和 4 。
节点 4 的值是 4，它有两个邻居：节点 1 和 3 。

示例 2：
输入：adjList = [[]]
输出：[[]]
解释：输入包含一个空列表。该图仅仅只有一个值为 1 的节点，它没有任何邻居。

示例 3：
输入：adjList = []
输出：[]
解释：这个图是空的，它不含任何节点。

提示：

这张图中的节点数在 [0, 100] 之间。
1 <= Node.val <= 100
每个节点值 Node.val 都是唯一的，
图中没有重复的边，也没有自环。
图是连通图，你可以从给定节点访问到所有节点。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/queue-stack/gmcr6/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <vector>
#include <stack>
#include <unordered_map>

class Node {
public:
    int val;
    std::vector<Node*> neighbors;
    Node() 
    {
        val = 0;
        neighbors = std::vector<Node*>();
    }
    Node(int _val) 
    {
        val = _val;
        neighbors = std::vector<Node*>();
    }
    Node(int _val, std::vector<Node*> _neighbors) 
    {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution 
{
    std::unordered_map<Node*, Node*> visit;
public:
    Node* cloneGraph(Node* node) 
    {
        if (node == nullptr)
        {
            return new Node();
        }
        DFS(node);
        for (auto [from, to]:visit)
        {
            for (auto i:from->neighbors)
            {
                to->neighbors.emplace_back(visit[i]);
            }
        }
        return visit[node];
    }

    void DFS(Node* node)
    {
        Node* newNode = new Node(node->val);
        visit[node] = newNode;
        for (auto i : node->neighbors)
        {
            if (!visit[i])
                DFS(i);
        }
    }
};