/* 题目描述: 221_基本计算器II
Given a string s which represents an expression, evaluate this expression and return its value. 
The integer division should truncate toward zero.
You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().

Example 1:
Input: s = "3+2*2"
Output: 7

Example 2:
Input: s = " 3/2 "
Output: 1

Example 3:
Input: s = " 3+5 / 2 "
Output: 5
*/
#include<vector>
#include<stack>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int calculate(string s) {
      stack<int> st;
      int index = 0;
      char op = '+';
      int currentNum = 0;
      while (index < s.length())
      {
        char currentChar = s[index];
        //如果是数字
        if(isdigit(currentChar)){
          // 将字符串类型的数字转换为整数
            currentNum = (currentNum * 10)+(currentChar -'0');
          }
        if(!isdigit(currentChar)&& !isspace(currentChar)|| index == s.length()-1){
          if(op == '+'){
            st.push(currentNum);
          }else if(op == '-'){
            st.push(-currentNum);
          }else if(op == '*'){
            int top = st.top();
            st.pop();
            st.push(top*currentNum);
          }else if(op == '/'){
            int top = st.top();
            st.pop();
            st.push(top/currentNum);
          }
          op = currentChar;
          currentNum = 0;
        }
        index++;
      }
      
      int sum = 0;
      while (!st.empty())
      {
        sum += st.top();
        st.pop();
      }
      return sum;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    EXPECT_EQ(7, solut.calculate("3+2*2"));
}

TEST(XXXTest, Case2){
    Solution solut;
    EXPECT_EQ(1, solut.calculate(" 3/2 "));
}

TEST(XXXTest, Case3){
    Solution solut;
    EXPECT_EQ(5, solut.calculate(" 3+5 / 2 "));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
