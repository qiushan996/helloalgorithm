/* 题目解析: 48_旋转图像

You are given an n x n 2D matrix representing an image, rotate the image by 90 degrees (clockwise).
给定一个代表图像的 n x n 二维矩阵，将图像旋转 90 度（顺时针）。


You have to rotate the image in-place, which means you have to modify the input 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.

您必须就地旋转图像，这意味着您必须直接修改输入的 2D 矩阵。请勿分配另一个 2D 矩阵并进行旋转。
 
Example1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [[7,4,1],[8,5,2],[9,6,3]]

Example2:
Input: matrix = [[5,1,9,11],[2,4,8,10],[13,3,6,7],[15,14,12,16]]
Output: [[15,13,2,5],[14,3,4,1],[12,6,8,9],[16,7,10,11]]

*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
      //
      int  n = matrix.size();

      for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
          swap(matrix[i][j], matrix[j][i]);
        }
      }

      for(int i = 0; i< n; i++){
        reverse(matrix[i].begin(), matrix[i].end());
      }

    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<vector<int>> input = {{1,2,3},{4,5,6},{7,8,9}};
    vector<vector<int>> target = {{7,4,1},{8,5,2},{9,6,3}};
    solut.rotate(input);
    EXPECT_EQ(target,input );
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<vector<int>> input = {{5,1,9,11},{2,4,8,10},{13,3,6,7},{15,14,12,16}};
    vector<vector<int>> target = {{15,13,2,5},{14,3,4,1},{12,6,8,9},{16,7,10,11}};
    solut.rotate(input);
    EXPECT_EQ(target,input );
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
