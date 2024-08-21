/*题目描述：移动零

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.

给一个整数数组，在不改变非零元素的前提下，将所有的0元素移动到数组末尾。只在原数组上操作，不能创建数组副本。

Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]

Example 2:
Input: nums = [0]
Output: [0]

*/


#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

void moveZeroes(vector<int>& nums) {
//解题思路：先将非零元素移动到数组前面、然后数组后面补零

  int nonZeroIndex = 0;
  for(int i=0;i<nums.size(); i++){
    if(nums[i]!=0){
      nums[nonZeroIndex] = nums[i];
      nonZeroIndex++;
    }
  }

  for(int i=nonZeroIndex; i<nums.size(); i++){
    nums[i]=0;
  }
}

TEST(MoveZeroTest, argv4){
  vector<int> input = {0,1,0,3,12};
  vector<int> target = {1,3,12,0,0};
  moveZeroes(input);
  EXPECT_EQ(target, input);
}

TEST(MoveZeroTest, argv0){
  vector<int> input = {0};
  vector<int> target = {0};
  moveZeroes(input);
  EXPECT_EQ(target, input);
}

int main(int argc, char* argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}