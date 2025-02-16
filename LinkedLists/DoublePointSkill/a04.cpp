/*
删除链表的倒数第N个节点
给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。

示例 1：
输入：head = [1,2,3,4,5], n = 2
输出：[1,2,3,5]

示例 2：
输入：head = [1], n = 1
输出：[]

示例 3：
输入：head = [1,2], n = 1
输出：[1]
 

提示：

链表中结点的数目为 sz
1 <= sz <= 30
0 <= Node.val <= 100
1 <= n <= sz
 

进阶：你能尝试使用一趟扫描实现吗？

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/linked-list/jf1cc/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>
#include <vector>

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if (head == nullptr)
        {
            return head;
        }
        ListNode *slow = head;

        while (slow != nullptr)
        {
            int i = 0;
            ListNode *fast = slow;
            while (i <= n)
            {
                if (fast == nullptr)
                {
                    return head->next; // 该情况表明应该删除头节点，例如{1， 2} 2
                }
                fast = fast->next;
                ++ i;
            }
            if (fast == nullptr)
            {
                break;
            }
            slow = slow->next;
        }

        if (slow->next != nullptr)
        {
            slow->next = slow->next->next;
        }
        else
        {
            head = nullptr;
        }
        return head;
    }
};

// 进阶
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        // 创建一个虚拟节点，方便处理头节点的删除
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
    
        for (int i = 0; i <= n; ++i) 
        {
            fast = fast->next;
        }
    
        while (fast != nullptr) 
        {
            fast = fast->next;
            slow = slow->next;
        }
    
        slow->next = slow->next->next;
    
        return dummy->next;
    }
};