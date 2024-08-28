/* 题目描述: 713_乘积小于K的子数组
Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.
给定一个整数数组 nums 和一个整数 k，返回连续子数组的数量，其中子数组中所有元素的乘积严格小于 k。

Example 1:
Input: nums = [10,5,2,6], k = 100
Output: 8
Explanation: The 8 subarrays that have product less than 100 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.

Example 2:
Input: nums = [1,2,3], k = 0
Output: 0
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
      //特殊情况 k=0
      if(k<=1) return 0;
      
      int len = nums.size();
      int left =0, right =0;
      int product =1;
      int ans =0;
      while (right <len)
      {
        product *= nums[right];
        while(product >= k){
          product /=nums[left];
          left++;
        }
        ans += (right -left +1);
        right++;
      }
      return ans;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> nums = {10,5,2,6};
    EXPECT_EQ(8, solut.numSubarrayProductLessThanK(nums, 100));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> nums = {1,2,3};
    EXPECT_EQ(0, solut.numSubarrayProductLessThanK(nums, 0));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
