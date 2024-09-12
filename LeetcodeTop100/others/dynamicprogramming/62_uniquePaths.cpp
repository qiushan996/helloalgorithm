/* 题目描述: 62_唯一路径

There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.

Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.

The test cases are generated so that the answer will be less than or equal to 2 * 109.
Example 1:
Input: m = 3, n = 7
Output: 28

Example 2:
Input: m = 3, n = 2
Output: 3
Explanation: From the top-left corner, there are a total of 3 ways to reach the bottom-right corner:
1. Right -> Down -> Down
2. Down -> Down -> Right
3. Down -> Right -> Down
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) {
      //动态规划题目dp
      //定义一个二维数组 dp，其中 dp[i][j] 表示从左上角走到网格位置 (i, j) 的不同路径数。显然，网格的边界（第一行和第一列）只能通过单一路径到达，因为它们只能从上方或左侧移动过来。
      //状态转移方程：
      // dp[i][j] = dp[i-1][j] + dp[i][j-1]
      // 其中 dp[i-1][j] 表示从上方到达 (i, j) 的路径数，dp[i][j-1] 表示从左侧到达 (i, j) 的路径数。

      vector<vector<int>> dp(m, vector<int>(n, 1));
      for(int i=1; i<m; i++){
        for(int j =1; j<n; j++){
          dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
      }
      return dp[m-1][n-1];
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    EXPECT_EQ(28, solut.uniquePaths(3, 7));
    EXPECT_EQ(3, solut.uniquePaths(3,2));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
