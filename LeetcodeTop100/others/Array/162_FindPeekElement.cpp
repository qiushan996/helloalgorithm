/* 题目描述: 162_寻找峰值

A peak element is an element that is strictly greater than its neighbors.

Given a 0-indexed integer array nums, find a peak element, and return its index. If the array contains multiple peaks, return the index to any of the peaks.

You may imagine that nums[-1] = nums[n] = -∞. In other words, an element is always considered to be strictly greater than a neighbor that is outside the array.

You must write an algorithm that runs in O(log n) time.

Example 1:
Input: nums = [1,2,3,1]
Output: 2
Explanation: 3 is a peak element and your function should return the index number 2.

Example 2:
Input: nums = [1,2,1,3,5,6,4]
Output: 5
Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.
*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      int left =0, right = nums.size()-1;
      
      while (left <right)
      {
        int mid = left + (right - left)/2;
        //峰值在右边
        if(nums[mid] < nums[mid +1]) {
          left = mid + 1;
        }
        else  {
          right = mid;
        }
      }
      return left;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> input = {1,2,3,1};
    EXPECT_EQ(2, solut.findPeakElement(input));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> input = {1,2,1,3,5,6,4};
    EXPECT_EQ(5, solut.findPeakElement(input));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
