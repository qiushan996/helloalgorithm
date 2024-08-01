/* 题目描述： 35_搜索插入位置

Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

给你个排序的整数数组和一个目标整数， 返回：
- 如果目标整数在数组中，返回坐标
- 如果不再数组中，返回应该插入的正确位置

You must write an algorithm with O(log n) runtime complexity.
算法复杂度为O(n)
 
Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2

Example 2:
Input: nums = [1,3,5,6], target = 2
Output: 1

Example 3:
Input: nums = [1,3,5,6], target = 7
Output: 4
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      int i = 0;
      if(target<=nums[0]) return 0;

      //Version 1: 这里没有体现出二分法的思想，需改进
      for(; i<nums.size()-1; i++){
        if(nums[i] == target) return i;
        else{
          if(target <= nums[i+1]){
          return i+1;
          }
        }
      }
      return i+1;
    }
};

//测试用例
TEST(XXXTest, Case1){
  vector<int> input = {1,3,5,6};
  int insert_target = 5;
  int output_target = 2;
  Solution solut;
  int result = solut.searchInsert(input, insert_target);
  EXPECT_EQ(output_target, result);
}

TEST(XXXTest, Case2){
  vector<int> input = {1,3,5,6};
  int insert_target = 2;
  int output_target = 1;
  Solution solut;
  int result = solut.searchInsert(input, insert_target);
  EXPECT_EQ(output_target, result);
}

TEST(XXXTest, Case3){
  vector<int> input = {1,3,5,6};
  int insert_target = 7;
  int output_target = 4;
  Solution solut;
  int result = solut.searchInsert(input, insert_target);
  EXPECT_EQ(output_target, result);
}

TEST(XXXTest, Case4){
  vector<int> input = {1,3,5,6};
  int insert_target = 0;
  int output_target = 0;
  Solution solut;
  int result = solut.searchInsert(input, insert_target);
  EXPECT_EQ(output_target, result);
}

int main(int argc, char* argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}