/*
反转链表
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。

示例 1：
输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]

示例 2：
输入：head = [1,2]
输出：[2,1]

示例 3：
输入：head = []
输出：[]

提示：

链表中节点的数目范围是 [0, 5000]
-5000 <= Node.val <= 5000
 
进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/linked-list/f58sg/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/

#include <iostream>
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 迭代
class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *cur = head;
        ListNode *pre = nullptr;

        while(cur != nullptr)
        {
            ListNode *end = cur->next;
            cur->next = pre;
            pre = cur;
            cur = end;
        }

        return pre;
    }
};

// 递归
class Solution 
{
public:
    ListNode* reverseList(ListNode* head) 
    {
        ListNode *cur = head;
        ListNode *pre = nullptr;
        pre = reverse(cur, pre);


        return pre;
    }

    ListNode* reverse(ListNode *cur , ListNode *pre)
    {
        if(cur == nullptr)
        {
            return pre;
        }
        ListNode *end = cur->next;
        cur->next  = pre;
        pre = cur;
        cur = end;
        pre = reverse(cur, pre);
        return pre;
    }
};