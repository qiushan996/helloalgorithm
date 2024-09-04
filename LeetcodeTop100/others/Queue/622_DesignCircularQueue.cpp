/*题目描述: 622_设计循环队列
Design your implementation of the circular queue. The circular queue is a linear data structure in which the operations are performed based on FIFO (First In First Out) principle, and the last position is connected back to the first position to make a circle. It is also called "Ring Buffer".

One of the benefits of the circular queue is that we can make use of the spaces in front of the queue. In a normal queue, once the queue becomes full, we cannot insert the next element even if there is a space in front of the queue. But using the circular queue, we can use the space to store new values.

Implement the MyCircularQueue class:

MyCircularQueue(k) Initializes the object with the size of the queue to be k.
int Front() Gets the front item from the queue. If the queue is empty, return -1.
int Rear() Gets the last item from the queue. If the queue is empty, return -1.
boolean enQueue(int value) Inserts an element into the circular queue. Return true if the operation is successful.
boolean deQueue() Deletes an element from the circular queue. Return true if the operation is successful.
boolean isEmpty() Checks whether the circular queue is empty or not.
boolean isFull() Checks whether the circular queue is full or not.

Input
["MyCircularQueue", "enQueue", "enQueue", "enQueue", "enQueue", "Rear", "isFull", "deQueue", "enQueue", "Rear"]
[[3], [1], [2], [3], [4], [], [], [], [4], []]
Output
[null, true, true, true, false, 3, true, true, true, 4]
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

//实现循环队列主要涉及到使用固定大小的数组和两个指针（头指针和尾指针）来维护队列的状态。
class MyCircularQueue {
private:
  vector<int> queue;
  int capacity;
  int tail;
  int head;
  int count;
public:
    MyCircularQueue(int k) {
      queue.resize(k);
      capacity = k;
      head = 0;
      tail = -1;
      count = 0;
    }
    
    bool enQueue(int value) {
      if(isFull()){
        return false;
      }
      tail = (tail+1)%capacity;
      queue[tail] = value;
      count++;
      return true;
    }
    
    bool deQueue() {
      if(isEmpty()){
        return false;
      }
      head = (head-1)%capacity;
      count--;
      return true;
    }
    
    int Front() {
      if(isEmpty())return -1;
      return queue[head];
    }
    
    int Rear() {
      if(isEmpty()) return -1;
      return queue[tail];
    }
    
    bool isEmpty() {
      return count==0;
    }
    
    bool isFull() {
      return count==capacity;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */

//测试用例
TEST(XXXTest, Case1){
    MyCircularQueue myqueue(3);
    myqueue.enQueue(1);
    myqueue.enQueue(2);
    myqueue.enQueue(3);
    EXPECT_FALSE(myqueue.isEmpty());
    EXPECT_TRUE(myqueue.isFull());
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
