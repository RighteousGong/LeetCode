/*
旋转链表
给你一个链表的头节点 head ，旋转链表，将链表每个节点向右移动 k 个位置。

 

示例 1：
输入：head = [1,2,3,4,5], k = 2
输出：[4,5,1,2,3]

示例 2：
输入：head = [0,1,2], k = 4
输出：[2,0,1]
 

提示：

链表中节点的数目在范围 [0, 500] 内
-100 <= Node.val <= 100
0 <= k <= 2 * 109

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/linked-list/f00a2/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution 
{
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }
        int len = getLength(head);
        int count = k % len;
        ListNode *newHead = head;
        for (size_t i = 0; i < count; i++)
        {
            newHead = rotate(newHead);
        }
        return newHead;
    }

    ListNode* rotate(ListNode* head)
    {
        ListNode *cur = head;
        while (cur->next->next != nullptr)
        {
            cur = cur->next;
        }
        ListNode *newNode = cur->next;
        cur->next = nullptr;
        newNode->next = head;
        return newNode;
    }

    int getLength(ListNode* head)
    {
        ListNode *cur = head;
        int len = 0;
        while (cur != nullptr)
        {
            cur = cur->next;
            ++len;
        }
        return len;
    }
};