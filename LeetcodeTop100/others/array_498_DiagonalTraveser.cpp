/*题目描述: 498_对角线遍历

Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

Example 1:
Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,4,7,5,3,6,8,9]

Example 2:
Input: mat = [[1,2],[3,4]]
Output: [1,2,3,4]
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    //对角线遍历可以通过模拟行走的路径来完成。
    //主要的挑战在于确定每次遍历的方向（向上或向下）以及如何处理边界条件（即当遍历到达矩阵的边缘时如何转向）。
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
      //特殊情况
      if(mat.empty()) return {};

      vector<int> result;
      int n = mat[0].size(), m = mat.size();
      
      int row = 0, col = 0, d =1;

      for(int i =0;i < m*n; i++){
        result.push_back(mat[row][col]);
        //向上移动
        if(d == 1){
          if(col == n-1) {row++; d = -1;}
          else if(row ==0) {col++; d =-1;}
          else {row--; col++;}
        }
        //向下移动
        else{
          if(row == m-1){col++; d =1;}
          else if(col == 0){row++; d =1;}
          else {row++; col--;}
        }
      }
      return result;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<vector<int>> input = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> target = {1,2,4,7,5,3,6,8,9};
    EXPECT_EQ(target, solut.findDiagonalOrder(input));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<vector<int>> input = {{1,2 },{3,4} };
    vector<int> target = {1,2,3,4};
    EXPECT_EQ(target, solut.findDiagonalOrder(input));
}
int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
