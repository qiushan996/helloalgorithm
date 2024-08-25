/* 题目描述: 415_字符串相加

Given two non-negative integers, num1 and num2 represented as string, return the sum of num1 and num2 as a string.

You must solve the problem without using any built-in library for handling large integers (such as BigInteger). You must also not convert the inputs to integers directly.

Example 1:
Input: num1 = "11", num2 = "123"
Output: "134"

Example 2:
Input: num1 = "456", num2 = "77"
Output: "533"

Example 3:
Input: num1 = "0", num2 = "0"
Output: "0"

*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    string addStrings(string num1, string num2) {
      string result;
      int i = num1.length()-1, j = num2.length()-1; 
      int carry =0;

      while (i >= 0 || j >= 0 || carry != 0) {
          int sum = carry;
          if (i >= 0) {
              sum += num1[i] - '0';
              i--;
          }
          if (j >= 0) {
              sum += num2[j] - '0';
              j--;
          }
          result.push_back(sum % 10 + '0');
          carry = sum / 10;
      }

      std::reverse(result.begin(), result.end());
      return result;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    EXPECT_EQ("134", solut.addStrings("11", "123"));
}

TEST(XXXTest, Case2){
    Solution solut;
    EXPECT_EQ("533", solut.addStrings("456", "77"));
}

TEST(XXXTest, Case3){
    Solution solut;
    EXPECT_EQ("0", solut.addStrings("0", "0"));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
