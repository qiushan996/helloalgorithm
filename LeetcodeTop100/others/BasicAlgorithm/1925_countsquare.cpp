/* 题目描述: 1925_统计平方和三元组的数目
基础算法题目: 枚举
A square triple (a,b,c) is a triple where a, b, and c are integers and a2 + b2 = c2.
Given an integer n, return the number of square triples such that 1 <= a, b, c <= n.

Example 1:
Input: n = 5
Output: 2
Explanation: The square triples are (3,4,5) and (4,3,5).

Example 2:
Input: n = 10
Output: 4
Explanation: The square triples are (3,4,5), (4,3,5), (6,8,10), and (8,6,10).

*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int countTriples(int n) {
      int ans = 0;
      for (int x = 1; x <= n; x++)
      {
        for (int y = 1; y <= n; y++)
        {
          for (int z = 1; z <= n; z++)
          {
            if(x*x+y*y == z*z) ans++;
          }
          // int squre = x*x + y*y;
          // int z = sqrt(squre);
          // if(z*z == squre && z <=n) ans++;
        }  
      }
      return ans;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    EXPECT_EQ(2, solut.countTriples(5));
}

TEST(XXXTest, Case2){
    Solution solut;
    EXPECT_EQ(4, solut.countTriples(10));
}



int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
