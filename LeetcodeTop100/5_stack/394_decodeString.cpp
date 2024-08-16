/* 题目描述: 394_字符串解码

Given an encoded string, return its decoded string.
给一个加密的字符串，返回解密后的字符串

The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.
加密规则：k[encoded_string]，其中方括号内的encoded_string重复k次。注意，k必须为正整数。

You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc. Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].
您可以假设输入字符串始终有效；没有多余的空格，方括号格式正确等。此外，您可以假设原始数据不包含任何数字，数字仅用于重复数字 k。例如，不会有像 3a 或 2[4] 这样的输入。

The test cases are generated so that the length of the output will never exceed 105.
生成测试用例的目的是确保输出的长度永远不会超过 105。
Example 1:
Input: s = "3[a]2[bc]"
Output: "aaabcbc"

Example 2:
Input: s = "3[a2[c]]"
Output: "accaccacc"

Example 3:
Input: s = "2[abc]3[cd]ef"
Output: "abcabccdcdcdef"
*/

#include<stack>
#include<string>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    string decodeString(string s) {
      //可以使用栈来解决，处理嵌套的编码结构。
      // 如果遇到数字，记录下来，因为数字可能由多位组成。
      // 如果遇到左括号，将之前的数字（即重复次数）和目前已经解码的字符串压入栈。
      // 如果遇到右括号，从栈中弹出数字和字符串，将字符串重复相应的次数并连接。
      // 如果遇到字母，将其添加到当前的解码字符串中。

      stack<string> strings;
      stack<int> counts;
      string current;

      int k =0;
      for(char ch:s){
        if(isdigit(ch)){
          k = k*10 + (ch-'0');
        }else if(ch == '['){
          counts.push(k);
          strings.push(current);
          current = "";
          k = 0;
        }else if(ch == ']'){
          string temp = current;
          current = strings.top();
          strings.pop();
          int count = counts.top(); counts.pop();
          for(int i=0; i<count; i++){
            current +=temp;
          }
        }else{
          current +=ch;
        }
      }
      return current;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    string s = "3[a]2[bc]";
    EXPECT_EQ("aaabcbc", solut.decodeString(s));
}

TEST(XXXTest, Case2){
    Solution solut;
    string s = "3[a2[c]]";
    EXPECT_EQ("accaccacc", solut.decodeString(s));
}

TEST(XXXTest, Case3){
    Solution solut;
    string s = "2[abc]3[cd]ef";
    EXPECT_EQ("abcabccdcdcdef", solut.decodeString(s));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
