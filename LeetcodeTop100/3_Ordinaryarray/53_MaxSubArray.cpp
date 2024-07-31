/* 题目描述:  53 最大字数组

Given an integer array nums, find the  subarray with the largest sum, and return its sum.
给定一个整数数组，找到有最大和的字数组。返回最大和。
 

Example 1:
Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
Output: 6
Explanation: The subarray [4,-1,2,1] has the largest sum 6.


Example 2:
Input: nums = [1]
Output: 1
Explanation: The subarray [1] has the largest sum 1.


Example 3:
Input: nums = [5,4,-1,7,8]
Output: 23
Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.

*/


#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
      int maxsum = nums[0];
      int currentsum = nums[0];  
      for(int i=1; i<nums.size(); i++){
        //从第二个元素开始，判断当前最大和与加nums[i] 之后的和
        currentsum = max(nums[i], currentsum + nums[i]);

        //更新最大和
        maxsum = max(maxsum, currentsum);

      }
      return maxsum;
    }
};


TEST(MaxSubArrayTest, Case1){
  vector<int>  input1 = {-2,1,-3,4,-1,2,1,-5,4};
  int target = 6;
  Solution solut;
  int result = solut.maxSubArray(input1);

  EXPECT_EQ(target, result);
}

TEST(MaxSubArrayTest, Case2){
  vector<int>  input2 = {1};
  int target = 1;
  Solution solut;
  int result = solut.maxSubArray(input2);

  EXPECT_EQ(target, result);
}

TEST(MaxSubArrayTest, Case3){
  vector<int>  input3 = {5,4,-1,7,8};
  int target = 23;
  Solution solut;
  int result = solut.maxSubArray(input3);
  EXPECT_EQ(target, result);
}


int main(int argc, char* argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}