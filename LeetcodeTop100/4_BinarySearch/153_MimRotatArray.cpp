/* 题目描述: 153_寻找循转数组中的最小值

Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.


Example 1:
Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.

Example 2:
Input: nums = [4,5,6,7,0,1,2]
Output: 0
Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.

Example 3:
Input: nums = [11,13,15,17]
Output: 11
Explanation: The original array was [11,13,15,17] and it was rotated 4 times. 
*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
      int start = 0;
      int end = nums.size() - 1;
      
      while (start < end)
      {
        if(nums[start] < nums[end]) return nums[start];

        int mid = (start + end ) >> 1 ;

        if(nums[mid] >= nums[start]){
          start = mid + 1;
        }else{
          end = mid;
        }

      }
      return nums[start];
    }
};

//测试用例
TEST(XXXTest, Case1){
  vector<int> input = {3,4,5,1,2};
  Solution solut;
  EXPECT_EQ(1, solut.findMin(input));
}

TEST(XXXTest, Case2){
  vector<int> input = {4,5,6,7,0,1,2};
  Solution solut;
  EXPECT_EQ(0, solut.findMin(input));
}

TEST(XXXTest, Case3){
  vector<int> input = {11,13,15,17};
  Solution solut;
  EXPECT_EQ(11, solut.findMin(input));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
