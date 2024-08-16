/*  题目描述:20_有效的括号
 
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
 

Example 1:
Input: s = "()"
Output: true

Example 2:
Input: s = "()[]{}"
Output: true

Example 3:
Input: s = "(]"
Output: false
*/

#include<stack>
#include<algorithm>
#include<string>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
    stack<char> brackets;
    for(char str : s) {
        switch (str) {
            case '(':
            case '[':
            case '{':
                brackets.push(str);
                break;
            case ')': 
                if(brackets.empty() || brackets.top() != '(') return false;
                brackets.pop();
                break;
            case ']':
                if(brackets.empty() || brackets.top() != '[') return false;
                brackets.pop();
                break;
            case '}':
                if(brackets.empty() || brackets.top() != '{') return false;
                brackets.pop();
                break;
            default:
                // 处理非括号字符，如果需要的话
                break;
        }
    }
    return brackets.empty();
    }
};

//测试用例
TEST(XXXTest, Case1){
  string  input = "()";
  Solution solut;
  EXPECT_TRUE(solut.isValid(input) );
}

TEST(XXXTest, Case2){
  string  input = "()[]{}";
  Solution solut;
  EXPECT_TRUE(solut.isValid(input) );
}

TEST(XXXTest, Case3){
  string  input = "(]";
  Solution solut;
  EXPECT_FALSE(solut.isValid(input) );
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
