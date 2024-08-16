/* 题目描述: 240_搜索二维矩阵
Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
编写一个有效的算法，在 m x n 整数矩阵中搜索值目标。此矩阵具有以下属性：

Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
每行中的整数按从左到右的升序排序。
每列中的整数按从上到下的升序排序。

Example1:
Input: matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}}, target = 5
Output: true

Example2:
Input: matrix = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}}, target = 20
Output: false

*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()|| matrix[0].empty()) return false;

        int m = matrix.size();
        int n = matrix[0].size();
        int row = 0;
        int col = n-1;

        while (row < m && col >=0)
        {
          if(matrix[row][col] == target) return true;

          else if( matrix[row][col] > target) col--;
          else row++;
        }
        return false;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<vector<int>> input = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    EXPECT_TRUE(solut.searchMatrix(input, 5));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<vector<int>> input = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    EXPECT_FALSE(solut.searchMatrix(input, 20));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
