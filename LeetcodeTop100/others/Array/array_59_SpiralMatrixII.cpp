/* 题目描述: 59_螺旋矩阵
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.
给定一个正整数 n，生成一个 n x n 矩阵，其中以螺旋顺序填充元素从 1 到 n2。

Example 1:
Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]

Example 2:
Input: n = 1
Output: [[1]]
*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> matrix(n, std::vector<int>(n));
    int num =1;
    int rowStart = 0, rowEnd = n -1; //行开始、结束
    int ColStart = 0, colEnd = n-1;  //列开始、结束

    while (rowStart <=rowEnd && ColStart<=colEnd)
    {
      //向右移动
      for(int j= ColStart; j<=colEnd; j++){
        matrix[rowStart][j] = num++;
      }
      rowStart++;
      //向下移动
      for(int i = rowStart; i<=rowEnd; i++){
        matrix[i][colEnd] = num++;
      }
      colEnd--;

      if(rowStart<=rowEnd){
        //向左移动
        for(int j=colEnd; j>=ColStart; j--){
          matrix[rowEnd][j] = num++;
        }
      }
      rowEnd--;

      if(ColStart <= colEnd){
        //向上移动
        for(int i=rowEnd; i>=rowStart; i--){
          matrix[i][ColStart] = num++;
        }
      }
      ColStart++;
    }
    return matrix;
  }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<vector<int>> result = {{1,2,3}, {8,9,4},{7,6,5}};
    EXPECT_EQ(solut.generateMatrix(3), result);
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<vector<int>> result = {{1}};
    EXPECT_EQ(solut.generateMatrix(1), result);
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
