/* 题目描述:64_最小路径和
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.
Example 2:
Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:
Input: grid = [[1,2,3],[4,5,6]]
Output: 12

*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

      int m = grid.size();
      int n = grid[0].size();

      //创建动态规划数组并初始化
      vector<vector<int>> dp(m, vector<int>(n, 0));
      dp[0][0] = grid[0][0];

      //初始化第一列
      for(int i=1; i<m; i++){
        dp[i][0] = dp[i-1][0] + grid[i][0];
      }
      for(int j=1; j<n; j++){
        dp[0][j] = dp[0][j-1] + grid[0][j];
      }

      for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
          dp[i][j] = min(dp[i-1][j], dp[i][j-1]) + grid[i][j];
        }
      }
      return dp[m-1][n-1];
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<vector<int>> input = {{1,3,1},{1,5,1},{4,2,1}};
    EXPECT_EQ(7, solut.minPathSum(input));
}
TEST(XXXTest, Case2){
    Solution solut;
    vector<vector<int>> input = {{1,2,3},{4,5,6}};
    EXPECT_EQ(12, solut.minPathSum(input));
}
int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
