/* 题目描述: 74_搜索二维矩阵

You are given an m x n integer matrix matrix with the following two properties:

Each row is sorted in non-decreasing order.
The first integer of each row is greater than the last integer of the previous row.
Given an integer target, return true if target is in matrix or false otherwise.



You must write a solution in O(log(m * n)) time complexity.
*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
      if(matrix.empty() ||matrix[0].empty()){
        return false;
      }

      int m = matrix.size();
      int n = matrix[0].size();
      int left = 0;
      int right = m * n - 1;

      while (left<=right)
      {
        int mid = left + (right - left )/2;
        int row = mid / n;
        int col = mid % n;
        int value = matrix[row][col];

        if(value == target){
          return true;
        }else if(value < target){
          left = mid + 1;
        }else{
          right = mid - 1;
        }       
      }
      return false;
    }
};

//测试用例
TEST(XXXTest, Case1){
  vector<vector<int>> input = {{1,3,5,7}, {10, 11, 16,20}, {23, 30, 34, 60}};
  int input_target = 3;
  Solution solut;
  int output = solut.searchMatrix(input, input_target);
  bool result = true;
  EXPECT_EQ(result, output);
}

TEST(XXXTest, Case2){
  vector<vector<int>> input = {{1,3,5,7}, {10, 11, 16,20}, {23, 30, 34, 60}};
  int input_target = 13;
  Solution solut;
  int output = solut.searchMatrix(input, input_target);
  bool result = false;
  EXPECT_EQ(result, output);
}



int main(int argc, char* argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}