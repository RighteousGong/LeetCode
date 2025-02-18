/*
回文链表
给你一个单链表的头节点 head ，请你判断该链表是否为回文链表。如果是，返回 true ；否则，返回 false 。

示例 1：
输入：head = [1,2,2,1]
输出：true

示例 2：
输入：head = [1,2]
输出：false 

提示：

链表中节点数目在范围[1, 105] 内
0 <= Node.val <= 9
 

进阶：你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/linked-list/fov6t/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    bool isPalindrome(ListNode* head) 
    {
        if (head == nullptr || head->next == nullptr) 
        {
            return true;
        }

        // 找中点
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast != nullptr)
        {
            slow = slow->next;
            if (fast->next == nullptr)
            {
                break;
            }
            fast = fast->next->next;
        }
        
        // 反转链表
        ListNode* pre = nullptr;
        while(slow != nullptr)
        {
            ListNode* temp = slow->next;
            slow->next = pre;
            pre = slow;
            slow = temp;
        }

        // 比较
        ListNode* curr = head;
        while (pre != nullptr)
        {
            if (pre->val != curr->val)
            {
                return false;
            }
            curr = curr->next;
            pre = pre->next;
        }
        return true;
    }
};