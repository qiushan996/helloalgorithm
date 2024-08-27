/*题目描述: 69_X的平方根
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.
For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
 
Example 1:
Input: x = 4
Output: 2
Explanation: The square root of 4 is 2, so we return 2.

Example 2:
Input: x = 8
Output: 2
Explanation: The square root of 8 is 2.82842..., and since we round it down to the nearest integer, 2 is returned.
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
      // if(x == 0) return 0;

      // int left =0, right = x;
      // while(left <=right){
      //有溢出
      //   int mid = left + (right - left)/2;
      //   if((mid*mid <=x) &&((mid+1)*(mid+1)>x)) return mid;
      //   else if(mid*mid > x) right = mid -1;
      //   else left = mid +1;
      // }
      // return right;

      if (x == 0) return 0;
      int left = 1, right = x, mid, sqrt;
      while (left <= right) {
          mid = left + (right - left) / 2;
          sqrt = x / mid; // 使用除法避免溢出
          if (sqrt == mid) {
              return mid;
          } else if (sqrt < mid) {
              right = mid - 1;
          } else {
              left = mid + 1;
          }
      }
      return right;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    EXPECT_EQ(2, solut.mySqrt(4));
}
TEST(XXXTest, Case2){
    Solution solut;
    EXPECT_EQ(2, solut.mySqrt(8));
}

TEST(XXXTest, Case3){
    Solution solut;
    EXPECT_EQ(0, solut.mySqrt(0));
}

// TEST(XXXTest, Case4){
//     Solution solut;
//     EXPECT_EQ(2, solut.mySqrt(2147395599));
// }
int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
