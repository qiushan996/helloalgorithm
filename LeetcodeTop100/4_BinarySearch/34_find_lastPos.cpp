/* 题目解析： 34_在排序数组中查找第一个和最后一个】

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

给一个升序排序的整数数组和一个给定的目标整数，找到该元素在数组中第一个和最后一个位置。

If target is not found in the array, return [-1, -1].
如果没有发现，则返回-1

You must write an algorithm with O(log n) runtime complexity.
算法复杂度为O(log n)

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]

Example 3:
Input: nums = [], target = 0
Output: [-1,-1]
*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

      vector<int> ret{-1, -1};
      //解法1：线性扫描  O(n)
      // for(int i=0; i<nums.size();i++){
      //   if(target == nums[i]){
      //     ret[0] = i;
      //     break;
      //   }
      // }

      // if(ret[0] == -1){
      //   return ret;
      // }

      // for(int i = nums.size()-1 ; i>=0;i--){
      //   if(target == nums[i]){
      //     ret[1] = i;
      //     break;
      //   }
      // }

      //解法2: 二分法
      //从左边查找第一个位置
      ret[0] = BinarySearch(nums, target, true);

      if(ret[0] == -1){
        return ret;
      }

      ret[1] = BinarySearch(nums, target, false);
 
      return ret;
    }

  private:
    int BinarySearch(vector<int>& nums, int target, bool leftmod){
      int left = 0;
      int right = nums.size()-1;
      int index = -1;

      while (left<=right)
      {
        int mid = left + (right-left)/2;
        if(nums[mid] == target){
          index  = mid;
          if(leftmod){
            right = mid -1;
          }else{
            left = mid + 1;
          }
        }else if(nums[mid]<target){
          left = mid + 1;
        }else{
          right = mid -1;
        }
      }
      return index;
    }
};

//测试用例
TEST(XXXTest, Case1){
  vector<int> input = {5,7,7,8,8,10};
  Solution solut;
  vector<int> result = solut.searchRange(input, 8);
  vector<int> target = {3, 4};
  EXPECT_EQ(target, result);
}

TEST(XXXTest, Case2){
  vector<int> input = {5,7,7,8,8,10};
  Solution solut;
  vector<int> result = solut.searchRange(input, 6);
  vector<int> target = {-1, -1};
  EXPECT_EQ(target, result);
}

TEST(XXXTest, Case3){
  vector<int> input = {};
  Solution solut;
  vector<int> result = solut.searchRange(input, 0);
  vector<int> target = {-1, -1};
  EXPECT_EQ(target, result);
}

int main(int argc, char* argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}