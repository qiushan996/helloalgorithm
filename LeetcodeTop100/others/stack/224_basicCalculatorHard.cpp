/*题目描述: 224_基本计算器(带括号)
Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:
Input: s = "1 + 1"
Output: 2

Example 2:
Input: s = " 2-1 + 2 "
Output: 3

Example 3:
Input: s = "(1+(4+5+2)-3)+(6+8)"
Output: 23
*/
#include<vector>
#include<stack>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
  int calculate(string s) {
    // 1.	初始化：设置一个变量 result 用来存储最终结果，number 用来构建当前读到的数，sign 用来表示当前的符号（初始化为 1 表示正号）。
    // 2.	遍历字符串：
    // •	如果遇到数字，则更新 number。
    // •	如果遇到符号 + 或 -，将之前的 number 与 result 相加（考虑到 sign），更新 sign，重置 number。
    // •	如果遇到左括号 (，将当前的 result 和 sign 压入栈，然后重置 result 和 sign。
    // •	如果遇到右括号 )，则先将当前的 number 加到 result 上，然后将 result 与栈顶的符号相乘（这是因为我们需要考虑到括号前的符号），然后加上之前的结果。
    // 3.	返回结果：处理完所有字符后，返回 result + number * sign，以确保最后一个数被正确加上。
    std::stack<int> stack;
    int result = 0;
    int number = 0;
    int sign = 1;  // 1 means positive, -1 means negative

    for (char c : s) {
        if (isdigit(c)) {
            number = 10 * number + (c - '0');
        } else if (c == '+') {
            result += sign * number;
            number = 0;
            sign = 1;
        } else if (c == '-') {
            result += sign * number;
            number = 0;
            sign = -1;
        } else if (c == '(') {
            // Push the result and the sign onto the stack, for later
            stack.push(result);
            stack.push(sign);
            // Reset the sign and result for the value in the parenthesis
            sign = 1;
            result = 0;
        } else if (c == ')') {
            result += sign * number;
            number = 0;
            result *= stack.top();  // stack.pop() is the sign before the parenthesis
            stack.pop();
            result += stack.top();  // stack.pop() now is the result calculated before the parenthesis
            stack.pop();
        }
    }

    return result + sign * number;
  }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    EXPECT_EQ(2, solut.calculate("1 + 1"));
}

TEST(XXXTest, Case2){
    Solution solut;
    EXPECT_EQ(3, solut.calculate(" 2-1 + 2 "));
}

TEST(XXXTest, Case3){
    Solution solut;
    EXPECT_EQ(23, solut.calculate("(1+(4+5+2)-3)+(6+8)"));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
