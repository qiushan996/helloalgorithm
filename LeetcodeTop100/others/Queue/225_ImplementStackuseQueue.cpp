/*题目描述: 225_用队列实现栈

Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

Implement the MyStack class:

void push(int x) Pushes element x to the top of the stack.
int pop() Removes the element on the top of the stack and returns it.
int top() Returns the element on the top of the stack.
boolean empty() Returns true if the stack is empty, false otherwise.
Notes:

You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.

Input
["MyStack", "push", "push", "top", "pop", "empty"]
[[], [1], [2], [], [], []]
Output
[null, null, null, 2, 2, false]

Explanation
MyStack myStack = new MyStack();
myStack.push(1);
myStack.push(2);
myStack.top(); // return 2
myStack.pop(); // return 2
myStack.empty(); // return False


*/
#include<vector>
#include<queue>
#include<gtest/gtest.h>

using namespace std;

class MyStack {
private:
    queue<int> qstack; 
public:
    MyStack() {
    }
    
    void push(int x) {
      qstack.push(x);
      int size = qstack.size();
      while(size>1){
        qstack.push(qstack.front());
        qstack.pop();
        size--;
      }
    }
    
    int pop() {
      int front = qstack.front();
      qstack.pop();
      return front;
    }
    
    int top() {
      return qstack.front();
    }
    
    bool empty() {
      return qstack.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

//测试用例
TEST(XXXTest, Case1){
    MyStack solut;
    solut.push(1);
    solut.push(2);
    EXPECT_EQ(2,solut.top());
    EXPECT_FALSE(solut.empty());
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
