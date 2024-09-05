/*题目描述: 150_逆波兰表达式求值
You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.
Evaluate the expression. Return an integer that represents the value of the expression.
逆波兰记法中，操作符置于操作数的后面。例如表达“三加四”时，写作“3 4 + ”，而不是“3 + 4”。如果有多个操作符，操作符置于第二个操作数的后面，所以常规中缀记法的“3 - 4 + 5”在逆波兰记法中写作“3 4 - 5 + ”：先3减去4，再加上5。使用逆波兰记法的一个好处是不需要使用括号。例如中缀记法中“3 - 4 * 5”与“（3 - 4）*5”不相同，但后缀记法中前者写做“3 4 5 * - ”，无歧义地表示“3 (4 5 *) -”；后者写做“3 4 - 5 * ”。

Note that:
The valid operators are '+', '-', '*', and '/'.
Each operand may be an integer or another expression.
The division between two integers always truncates toward zero.
There will not be any division by zero.
The input represents a valid arithmetic expression in a reverse polish notation.
The answer and all the intermediate calculations can be represented in a 32-bit integer.
 

Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:
Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6
Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

*/
#include<vector>
#include<stack>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
      stack<int> stack;  //初始化栈，用于存储数字
      for(const string& token: tokens){
        if(token == "+" || token == "-" || token == "*" || token == "/"){
          int num1 = stack.top();
          stack.pop();
          int num2 = stack.top();
          stack.pop();
          //弹出栈顶前两个数字进行计算
          if(token == "+"){
            stack.push(num2 + num1);
          }else if(token== "-"){
            stack.push(num2 - num1);
          }else if(token == "*"){
            stack.push(num2 * num1);
          }else if(token =="/"){
            stack.push(num2 / num1);
          }
        }else{
          stack.push(stoi(token));
        }  
      }
      return stack.top();
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<string> input = {"10","6","9","3","+","-11","*","/","*","17","+","5","+"};
    EXPECT_EQ(22, solut.evalRPN(input));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<string> input = {"4","13","5","/","+"};
    EXPECT_EQ(6, solut.evalRPN(input));
}

TEST(XXXTest, Case3){
    Solution solut;
    vector<string> input = {"2","1","+","3","*"};
    EXPECT_EQ(9, solut.evalRPN(input));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
