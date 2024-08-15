/* 题目解析：73_矩阵置零

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

给定一个 m x n 整数矩阵，如果一个元素为 0，则将其整个行和列设置为 0。

Example1:
Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]

Example2:
Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]

Example3:

*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
      int m = matrix.size();
      int n = matrix[0].size();
      bool firstRow = false;
      bool firstCol = false;

      //第一行是否被置零
      for(int j =0 ;j<n; j++){
        if(matrix[0][j] == 0){
          firstRow = true;
          break;
        }
      }

      //第一列是否被置零
      for(int i =0 ; i< m; i++){
        if(matrix[i][0] == 0){
          firstCol = true;
          break;
        }
      }

      //判断剩余元素是否被置零
      for(int i = 1; i< m ;i++){
        for( int j = 1; j < n; j++){
          if(matrix[i][j] == 0){
            matrix[0][j] = 0;
            matrix[i][0] = 0;
          }
        }
      }
      //
      for(int i = 1; i< m; i++){
        for (int j=1; j< n; j++){
          if(matrix[i][0] == 0 || matrix[0][j] == 0){
            matrix[i][j] = 0;
          }
        }
      }

      //第一行置零
      if(firstRow){
        for(int j=0; j< n; j++){
          matrix[0][j] = 0;
        }
      }

      //第一列置零
      if(firstCol ){
        for(int i=0; i<m; i++){
          matrix[i][0] = 0;
        }
      }
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<vector<int>> input = {{1,1,1},{1,0,1},{1,1,1}};
    vector<vector<int>> target = {{1,0,1},{0,0,0},{1,0,1}};
    solut.setZeroes(input);

    EXPECT_EQ(target, input);
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<vector<int>> input = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    vector<vector<int>> target = {{0,0,0,0},{0,4,5,0},{0,3,1,0}};
    solut.setZeroes(input);

    EXPECT_EQ(target, input);
}


int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
