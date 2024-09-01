/*题目描述: 338_比特位计数
Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Example 1:
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
Example 2:

Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
      vector<int> result;
      result.push_back(0);
      for (int i = 1; i <= n; i++)
      {
        //十进制转换成二进制；统计其中1的个数
        int count = 0;
        int tmp = i;
        while (tmp!=0)
        {
          //tmp &= (tmp -1);
          if(tmp & 1) count++;
          tmp >>=1;
        }
        result.push_back(count);
        
      }
      return result;

    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> target = {0,1,1};
    EXPECT_EQ(target, solut.countBits(2));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> target = {0,1,1,2,1,2};
    EXPECT_EQ(target, solut.countBits(5));
}


int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
