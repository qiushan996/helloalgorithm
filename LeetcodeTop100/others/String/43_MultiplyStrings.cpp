/* 题目描述: 43_字符串相乘

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
Note: You must not use any built-in BigInteger library or convert the inputs to integer directly.
注意：不能使用任何内置的 BigInteger 库，也不能直接将输入的字符串转换为整数形式

Example 1:
Input: num1 = "2", num2 = "3"
Output: "6"

Example 2:
Input: num1 = "123", num2 = "456"
Output: "56088"
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
      // if(num1 == "0" || num2 == "0") return "0";

      // int m = num1.size(), n = num2.size();
      // std::vector<int> pos(m+n, 0);

      // for (int i = m-1; i >= 0; i--)
      // {
      //   for (int j = n-1 ; j>=0; j--)
      //   {
      //     int mul = (num1[i] - '0') *(num2[j]-'0');
      //     int p1 = i + j, p2 = i + j +1;
      //     int sum = mul + pos[p2];

      //     pos[p1] += sum /10;
      //     pos[p2] = sum % 10;
      //   }
        
      // }
      // string result;
      // for(int p: pos){
      //   if(!(result.empty() && p == 0)){
      //     result.push_back(p + '0');
      //   }
      // }
      // return result.empty() ? "0":result;

      if (num1 == "0" || num2 == "0") return "0";
      
      int m = num1.size(), n = num2.size();
      std::vector<int> pos(m + n, 0);
      
      for (int i = m - 1; i >= 0; i--) {
          for (int j = n - 1; j >= 0; j--) {
              int mul = (num1[i] - '0') * (num2[j] - '0');
              int p1 = i + j, p2 = i + j + 1;
              int sum = mul + pos[p2];
              
              pos[p1] += sum / 10;
              pos[p2] = sum % 10;
          }
      }
      
      std::string result;
      for (int p : pos) {
          if (!(result.empty() && p == 0)) { // Skip leading zeros
              result.push_back(p + '0');
          }
      }
      return result.empty() ? "0" : result;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    string num1 = "2", num2 = "3";
    EXPECT_EQ("6", solut.multiply(num1, num2));
}

TEST(XXXTest, Case2){
    Solution solut;
    EXPECT_EQ("56088", solut.multiply("123", "456"));
}
int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
