/* 题目描述: 504_7进制数
Given an integer num, return a string of its base 7 representation.

Example 1:
Input: num = 100
Output: "202"

Example 2:
Input: num = -7
Output: "-10"
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    string convertToBase7(int num) {
      if(num==0) return "0";
      string result;
      int value = abs(num);
      while(value>0){
        //进制转化：10进制转7进制
         result.append(to_string(value%7));
         value /=7;
      }

      std::reverse(result.begin(), result.end()); // 反转
      return num >0 ? result: "-"+result;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    EXPECT_EQ("202", solut.convertToBase7(100));
}

TEST(XXXTest, Case2){
    Solution solut;
    EXPECT_EQ("-10", solut.convertToBase7(-7));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
