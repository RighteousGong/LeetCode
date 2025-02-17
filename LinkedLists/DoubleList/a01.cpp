/*
设计链表
你可以选择使用单链表或者双链表，设计并实现自己的链表。

单链表中的节点应该具备两个属性：val 和 next 。val 是当前节点的值，next 是指向下一个节点的指针/引用。

如果是双向链表，则还需要属性 prev 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

实现 MyLinkedList 类：

MyLinkedList() 初始化 MyLinkedList 对象。
int get(int index) 获取链表中下标为 index 的节点的值。如果下标无效，则返回 -1 。
void addAtHead(int val) 将一个值为 val 的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
void addAtTail(int val) 将一个值为 val 的节点追加到链表中作为链表的最后一个元素。
void addAtIndex(int index, int val) 将一个值为 val 的节点插入到链表中下标为 index 的节点之前。如果 index 等于链表的长度，那么该节点会被追加到链表的末尾。如果 index 比长度更大，该节点将 不会插入 到链表中。
void deleteAtIndex(int index) 如果下标有效，则删除链表中下标为 index 的节点。
 

示例：

输入
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
输出
[null, null, null, null, 2, null, 3]

解释
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // 链表变为 1->2->3
myLinkedList.get(1);              // 返回 2
myLinkedList.deleteAtIndex(1);    // 现在，链表变为 1->3
myLinkedList.get(1);              // 返回 3
 

提示：

0 <= index, val <= 1000
请不要使用内置的 LinkedList 库。
调用 get、addAtHead、addAtTail、addAtIndex 和 deleteAtIndex 的次数不超过 2000 。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/linked-list/jy291/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <iostream>

class MyLinkedList {
public:
    MyLinkedList() 
    {
        head = nullptr;
    }

    ~MyLinkedList() 
    {
        DoublyListNode *cur = head;
        DoublyListNode *nextNode = nullptr;

        while (cur != nullptr) 
        {
            nextNode = cur->next;
            delete cur;
            cur = nextNode;
        }
    }
    
    int get(int index) 
    {
        if (index < 0 || head == nullptr) 
        {
            return -1;
        }

        int i = 0;
        DoublyListNode *next = head;
        while (next != nullptr) 
        {
            if (i == index) 
            {
                return next->val;
            }
            ++i;
            next = next->next;
        }
        return -1;
    }

    void addAtHead(int val) 
    {
        DoublyListNode *newHead = new DoublyListNode(val);
        if (head != nullptr) 
        {
            newHead->next = head;
            head->prev = newHead;
        }
        head = newHead;
    }

    void addAtTail(int val) 
    {
        if (head == nullptr) 
        {
            head = new DoublyListNode(val);
        } 
        else 
        {
            DoublyListNode *newNode = new DoublyListNode(val);
            DoublyListNode *curr = head;
            while (curr->next != nullptr) 
            {
                curr = curr->next;
            }
            curr->next = newNode;
            newNode->prev = curr;
        }
    }

    void addAtIndex(int index, int val) 
    {
        if (index == 0) 
        {
            addAtHead(val);
            return;
        }

        DoublyListNode *curr = head;
        int i = 0;
        while (curr != nullptr && i < index - 1) 
        {
            curr = curr->next;
            ++i;
        }

        if (curr == nullptr) 
        {
            return;
        }

        DoublyListNode *newNode = new DoublyListNode(val);
        newNode->next = curr->next;
        if (curr->next != nullptr) 
        {
            curr->next->prev = newNode;
        }
        curr->next = newNode;
        newNode->prev = curr;
    }

    void deleteAtIndex(int index) 
    {
        if (index < 0 || head == nullptr) 
        {
            return;
        }

        DoublyListNode *curr = head;
        int i = 0;

        if (index == 0) {
            if (head->next != nullptr) 
            {
                head = head->next;
                head->prev = nullptr;
            } 
            else 
            {
                head = nullptr;
            }
            return;
        }

        while (curr != nullptr && i < index) 
        {
            curr = curr->next;
            ++i;
        }

        if (curr == nullptr) 
        {
            return;
        }

        if (curr->next != nullptr) 
        {
            curr->next->prev = curr->prev;
        }
        if (curr->prev != nullptr) 
        {
            curr->prev->next = curr->next;
        }

        delete curr;
    }

    void printList()
    {
        DoublyListNode *curr = head;
        while (curr != nullptr) {
            std::cout << curr->val << " ";
            curr = curr->next;
        }
        std::cout << std::endl;
    }

private:
    struct DoublyListNode {
        int val;
        DoublyListNode *next, *prev;

        DoublyListNode(int val) : val(val), next(nullptr), prev(nullptr) {}
    };

    DoublyListNode *head;
};