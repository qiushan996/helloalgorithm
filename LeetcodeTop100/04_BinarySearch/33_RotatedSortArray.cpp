/*  题目描述：33_寻找旋转数组
 
There is an integer array nums sorted in ascending order (with distinct values).

题目大意：有一个排序的整数数组(在某一点上存在旋转)，查找目标整数在该数组中的坐标。
正常使用二分法时，数组是严格按照升序或将序排列的。 本题目的特点是对排序的数组做了一点点变化。

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

You must write an algorithm with O(log n) runtime complexity.  算法复杂度O(log n)

Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1

Example 3:
Input: nums = [1], target = 0
Output: -1
*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
      int start = 0;
      int end = nums.size() -1;
      while(start<=end){
        int mid = (start + end)/2;
        //  中间就是target，唯一的终止条件
        if(target == nums[mid]) return mid;

        //左段有序
        if(nums[start] <= nums[mid]){
          if(target >= nums[start] && target <= nums[mid]){
            end = mid - 1;
          }else{
            start = mid + 1;
          }
        }else{
          //右端有序
          if(target >= nums[mid] && target <= nums[end]){
            start = mid +1;
          }else{
            end = mid - 1;
          }
        }
      }
      return -1;
    }
};

//测试用例
TEST(XXXTest, Case1){
  vector<int>  input = {4,5,6,7,0,1,2};
  Solution solut;
  EXPECT_EQ(4, solut.search(input, 0));
}

TEST(XXXTest, Case2){
  vector<int>  input = {4,5,6,7,0,1,2};
  Solution solut;
  EXPECT_EQ(-1, solut.search(input, 3));
}

TEST(XXXTest, Case3){
  vector<int>  input = {1};
  Solution solut;
  EXPECT_EQ(-1, solut.search(input, 0));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
