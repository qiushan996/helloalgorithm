/*题目描述: 371_两个整数之和
位运算：不使用+ 和 - 计算两个整数之和

Given two integers a and b, return the sum of the two integers without using the operators + and -.
Example 1:
Input: a = 1, b = 2
Output: 3
Example 2:
Input: a = 2, b = 3
Output: 5
*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int getSum(int a, int b) {
      //利用二进制位运算实现 + -
      //基本思路是使用位运算符 ^（异或）和 &（与）来实现，其中异或运算用来计算无进位加法，与运算后左移一位用来计算进位。
      // 1.	无进位求和：使用异或运算 ^ 来模拟无进位求和。
      // 2.	计算进位：使用与运算 & 来找到哪些位会产生进位，并将结果左移一位来模拟进位后的值。
      // 3.	迭代：重复上述两步，直到进位为0，此时异或运算的结果就是最终的求和结果。
      while (b !=0)
      {
        unsigned carry = (a&b)<<1;
        a = a^b;
        b = carry;
      }
      
      return a;

    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    EXPECT_EQ(3, solut.getSum(1, 2));
}

TEST(XXXTest, Case2){
    Solution solut;
    EXPECT_EQ(5, solut.getSum(2, 3));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
