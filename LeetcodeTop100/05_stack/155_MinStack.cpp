/* 题目描述: 155_最小栈
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
设计一个支持入栈、出栈、顶栈以及在常数时间内检索最小元素的堆栈。

Implement the MinStack class:
MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
  //使用两个栈
    stack<int> mainStack ;  
    stack<int> minStack ;   //保存最小值
public:
    MinStack() {
    }
    
    void push(int val) {
        mainStack.push(val);
        if(minStack.empty() || val <= minStack.top()){
            minStack.push(val);
        }
    }
    
    void pop() {
    if (mainStack.top() == minStack.top()) {
                minStack.pop();
            }
            mainStack.pop();
        }
    
    int top() {
      assert(!mainStack.empty());
        return mainStack.top();
    }
    
    int getMin() {
        assert(!minStack.empty());
        return minStack.top();
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    //
    EXPECT_EQ(target, result);
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
