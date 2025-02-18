/*
两数相加
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例 1：
输入：l1 = [2,4,3], l2 = [5,6,4]
输出：[7,0,8]
解释：342 + 465 = 807.

示例 2：
输入：l1 = [0], l2 = [0]
输出：[0]

示例 3：
输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
输出：[8,9,9,9,0,0,0,1]
 

提示：

每个链表中的节点数在范围 [1, 100] 内
0 <= Node.val <= 9
题目数据保证列表表示的数字不含前导零

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/linked-list/fv6w7/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include "../tool.h"

// struct ListNode 
// {
//     int val;
//     ListNode *next;
//     ListNode() : val(0), next(nullptr) {}
//     ListNode(int x) : val(x), next(nullptr) {}
//     ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// 空间复杂度大
class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(l1 == nullptr)
        {
            return l2;
        }
        if (l2 == nullptr)
        {
            return l1;
        }

        ListNode* head = new ListNode(0);
        ListNode* node = head;
        
        bool isCarry = false;
        while (l1!=nullptr || l2 != nullptr || isCarry)
        {
            int sum = isCarry;
            if (l1 != nullptr)
            {
                sum += l1->val;
                l1 = l1->next;
            }
            if (l2 != nullptr)
            {
                sum += l2->val;
                l2 = l2->next;
            }

            if (sum >= 10)
            {
                isCarry = true;
            }
            else
            {
                isCarry = false;
            }
            ListNode* tmp = new ListNode(sum%10);
            node->next = tmp;
            node = node->next;
        }
        
        return head->next;
        
    }
};

class Solution 
{
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
        if(l1 == nullptr)
        {
            return l2;
        }
        if (l2 == nullptr)
        {
            return l1;
        }

        ListNode* head = l1;
        ListNode* curr = head;
        
        bool isCarry = false;
        while (l1 != nullptr && l2 != nullptr)
        {
            int sum = l1->val + l2->val + isCarry;
            isCarry = (sum >= 10);
            l1->val = sum%10;
            l2 = l2->next;
            l1 = l1->next;
            if (curr->next == nullptr)
            {
                break;
            }
            curr = curr->next;
        }

        while (isCarry && l2 != nullptr)
        {
            int sum = l2->val + isCarry;
            isCarry = (sum >= 10);
            l2->val = sum%10;
            curr->next = l2;
            curr = l2;
            l2 = l2->next;
        }
        while (isCarry && l1 != nullptr)
        {
            int sum = l1->val + isCarry;
            isCarry = (sum >= 10);
            l1->val = sum%10;
            l1 = l1->next;
            if (curr->next == nullptr)
            {
                break;
            }
            curr = curr->next;
        }

        if (l2 != nullptr)
        {
            curr->next = l2;
        }
        if (isCarry)
        {
            isCarry = false;
            ListNode *node = new ListNode(1);
            curr->next = node;
        }
        return head;
    }
};

int main()
{
    // ListNode* l1 = createLinkedList({5});
    // ListNode* l2 = createLinkedList({5});
    // ListNode* l1 = createLinkedList({9,9,9,9,9,9});
    // ListNode* l2 = createLinkedList({9,9,9});
    ListNode* l1 = createLinkedList({2,4,9});
    ListNode* l2 = createLinkedList({5,6,4,9});
    Solution sol;
    printList(sol.addTwoNumbers(l1, l2));
}