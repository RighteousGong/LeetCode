/*
设计循环队列
设计你的循环队列实现。 循环队列是一种线性数据结构，其操作表现基于 FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。

循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。

你的实现应该支持如下操作：

MyCircularQueue(k): 构造器，设置队列长度为 k 。
Front: 从队首获取元素。如果队列为空，返回 -1 。
Rear: 获取队尾元素。如果队列为空，返回 -1 。
enQueue(value): 向循环队列插入一个元素。如果成功插入则返回真。
deQueue(): 从循环队列中删除一个元素。如果成功删除则返回真。
isEmpty(): 检查循环队列是否为空。
isFull(): 检查循环队列是否已满。
 

示例：

MyCircularQueue circularQueue = new MyCircularQueue(3); // 设置长度为 3
circularQueue.enQueue(1);  // 返回 true
circularQueue.enQueue(2);  // 返回 true
circularQueue.enQueue(3);  // 返回 true
circularQueue.enQueue(4);  // 返回 false，队列已满
circularQueue.Rear();  // 返回 3
circularQueue.isFull();  // 返回 true
circularQueue.deQueue();  // 返回 true
circularQueue.enQueue(4);  // 返回 true
circularQueue.Rear();  // 返回 4
 

提示：

所有的值都在 0 至 1000 的范围内；
操作数将在 1 至 1000 的范围内；
请不要使用内置的队列库。

作者：LeetCode
链接：https://leetcode.cn/leetbook/read/queue-stack/kzlb5/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
*/
#include <vector>

// size版本
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        data = std::vector<int>(k);
    }
    
    bool enQueue(int value) {
        if (isFull())
        {
            return false;
        }
        ++ size;
        head = head < 0 ? ++head : head;
        tail = ++tail >= data.size() ? 0 : tail;
        data[tail] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty())
        {
            return false;
        }
        -- size;
        data[head] = -1;
        head = ++head >= data.size() ? 0 : head;
        return true;
    }
    
    int Front() {
        if (isEmpty())
        {
            return -1;
        }
        return data[head];
    }
    
    int Rear() {
        if (isEmpty())
        {
            return -1;
        }
        return data[tail];
    }
    
    bool isEmpty() {
        return size <= 0;
    }
    
    bool isFull() {
        return size == data.size();
    }
private:
    std::vector<int> data;
    int head = -1;
    int tail = -1;
    int size = 0;
};

// 无size版本
class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        data = std::vector<int>(k);
    }
    
    bool enQueue(int value) {
        if (isFull())
        {
            return false;
        }
        head = head < 0 ? ++head : head;
        tail = ++tail >= data.size() ? 0 : tail;
        data[tail] = value;
        return true;
    }
    
    bool deQueue() {
        if (isEmpty())
        {
            return false;
        }
        data[head] = -1;
        if (head != tail)
        {
            head = ++head >= data.size() ? 0 : head;
        }
        else
        {
            head = -1;
            tail = -1;
        }
        return true;
    }
    
    int Front() {
        if (isEmpty())
        {
            return -1;
        }
        return data[head];
    }
    
    int Rear() {
        if (isEmpty())
        {
            return -1;
        }
        return data[tail];
    }
    
    bool isEmpty() {
        return head == -1;
    }
    
    bool isFull() {
        int tmpTail = tail+1 >= data.size() ? 0 : tail+1;
        return tmpTail == head;
    }
private:
    std::vector<int> data;
    int head = -1;
    int tail = -1;
};