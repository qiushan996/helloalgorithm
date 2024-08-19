/* 题目描述: 70_爬楼梯

You are climbing a staircase. It takes n steps to reach the top.
你正在爬楼梯。需要走 n 级台阶才能到达顶部。
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
每次你可以爬 1 或 2 个台阶。有多少种不同的方法可以爬到顶部？
 

Example 1:
Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Example 2:
Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step

*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
      //使用动态规划解
      vector<int> dp(n+1);
      dp[0] = 1;
      dp[1] = 2;
      for(int i=2; i<n; i++){
        dp[i] = dp[i-1]+dp[i-2];
      }
     return dp[n-1];  
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    EXPECT_EQ(2, solut.climbStairs(2));
}

TEST(XXXTest, Case2){
    Solution solut;
    EXPECT_EQ(3, solut.climbStairs(3));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
