/* 题目描述: 50_Powx(x,  n)
Implement pow(x, n), which calculates x raised to the power n (i.e., xn).
实现 pow(x, n)，它计算 x 的 n 次方（即 xn）。
Example 1:
Input: x = 2.00000, n = 10
Output: 1024.00000

Example 2:
Input: x = 2.10000, n = 3
Output: 9.26100

Example 3:
Input: x = 2.00000, n = -2
Output: 0.25000
Explanation: 2-2 = 1/22 = 1/4 = 0.25
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
      //快速幂+递归
      if (n == 0) return 1.0;
      if (n == 1) return x;
      if (n == -1) return 1 / x;

      //快速幂算法利用了幂运算的性质，即 x^n 可以分解为 (x^{n/2})^2 （当 n 为偶数时）或 (x^{n/2})^2 \times x （当 n 为奇数时）。
      double half = myPow(x, n / 2);
      double rest = myPow(x, n % 2);  //n%2  1:0

      return half * half * rest;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    EXPECT_EQ(1024.0, solut.myPow(2.00000, 10));
}
TEST(XXXTest, Case2){
    Solution solut;
    EXPECT_EQ(9.261, solut.myPow(2.10000, 3));
}

// TEST(XXXTest, Case3){
//     Solution solut;
//     EXPECT_EQ(0.25000, solut.myPow(2.00000, -2));
// }


int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
