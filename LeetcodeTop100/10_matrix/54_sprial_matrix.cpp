/* 题目解析: 54_螺旋矩阵

Given an m x n matrix, return all elements of the matrix in spiral order.

给定一个 m x n 矩阵，按螺旋顺序返回矩阵的所有元素。

Example1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

      vector<int> result;
      if(matrix.empty()|| matrix[0].empty()) return result;

      int m = matrix.size(), n = matrix[0].size();
      int left = 0, right = n-1, top = 0, bottom = m -1;

      while (left <= right && top <=bottom)
      {
        //向右移动
        for(int j = left; j<=right; j++){
          result.push_back(matrix[top][j]);
        }
        top++;

        //向下移动
        for(int i = top; i<=bottom ; i++){
          result.push_back(matrix[i][right]);
        }
        right--;

        if(top <= bottom){
          //向左移动
          for(int j = right; j >=left; j--){
            result.push_back(matrix[bottom][j]);
          }
          bottom--;
        }

        if(left <=right){
          for(int i = bottom; i>= top; i--){
            result.push_back(matrix[i][left]);
          }
          left++;
        }
      }
      return result;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<vector<int>> input = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> target = {1,2,3,6,9,8,7,4,5};
    EXPECT_EQ(target, solut.spiralOrder(input));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<vector<int>> input = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};
    vector<int> target = {1,2,3,4,8,12,11,10,9,5,6,7};
    EXPECT_EQ(target, solut.spiralOrder(input));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
