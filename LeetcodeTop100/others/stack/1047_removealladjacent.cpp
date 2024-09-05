/*题目描述: 1047_删除字符串中所有相邻重复项
You are given a string s consisting of lowercase English letters. A duplicate removal consists of choosing two adjacent and equal letters and removing them.
We repeatedly make duplicate removals on s until we no longer can.
Return the final string after all such duplicate removals have been made. It can be proven that the answer is unique.

Example 1:
Input: s = "abbaca"
Output: "ca"
Explanation: 
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".

Example 2:
Input: s = "azxxzy"
Output: "ay"
*/
#include<vector>
#include<stack>
#include<string>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    string removeDuplicates(string s) {
    //   stack<char> st;
    //   for(int i=0; i<s.length(); i++){
    //     char current = s[i];
    //     //如果当前字符==栈顶字符，则追加到栈中
    //     if(current == st.top() && !st.empty()){
    //         st.pop();
    //     }else{
    //       //如果当前字符!=栈顶字符，弹出栈顶字符，
    //       st.push(current);
    //     }
    //   }
    //   std::cout<<s<<std::endl;
    //   // 逆序数处字符串
    //   string ret;
    //   while(!st.empty()){
    //     ret += st.top();
    //     st.pop();
    //   }
    //   return ret;
    // }


    // std::stack<char> st;
    // for (int i = 0; i < s.length(); i++) {
    //     char current = s[i];
    //     if (!st.empty() && current == st.top()) { // 检查栈是否为空并比较栈顶
    //         st.pop(); // 如果当前字符等于栈顶字符，弹出栈顶字符
    //     } else {
    //         st.push(current); // 如果不等，或栈为空，压入当前字符
    //     }
    // }

    // // 构建结果字符串，栈中的字符顺序需要反转
    // std::string ret;
    // while (!st.empty()) {
    //     ret += st.top();
    //     st.pop();
    // }
    // // 因为栈是LIFO，得到的字符串是反转的，需要再反转一次以匹配原字符串顺序
    // std::reverse(ret.begin(), ret.end());
    // return ret;

    stack<char> stack;
    for(char ch: s){
      if(!stack.empty() && ch==stack.top()){
        stack.pop();
      }else{
        stack.push(ch);
      }
    }
          //
    string result;
    while(!stack.empty()){
      result = stack.top() + result;   //这样写返回之前不需要逆序
      stack.pop();
    }
    //reverse(result.begin(), result.end());  //是否逆序根据result的构造决定
    return result;
  }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    EXPECT_EQ("ca", solut.removeDuplicates("abbaca"));
}

TEST(XXXTest, Case2){
    Solution solut;
    EXPECT_EQ("ay", solut.removeDuplicates("azxxzy"));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
