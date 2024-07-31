/* 题目解析: 238_除自身以外数组的乘积
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
给一个整数数组，返回一个数组，该数组的每一项为除自身元素外所有元素的乘积。

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
任何 nums 的前缀或后缀的乘积都保证适合 32 位整数。

You must write an algorithm that runs in O(n) time and without using the division operation.
算法时间复杂度为O(n)

 
Example 1:
Input: nums = [1,2,3,4]
Output: [24,12,8,6]


Example 2:
Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
*/

#include<vector>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n = nums.size();
      vector<int> result(n,1);
      //计算左侧乘积
      int left = 1;
      for(int i=0;i<n; i++){
        result[i] *= left;
        left *= nums[i];
      }

      int right =1;
      for(int i=n-1; i>=0; i--){
        result[i] *= right;
        right *= nums[i];
      }
      return result;   
    }
};

//测试用例
TEST(XXXTest, Case1){
  vector<int> input = {1,2,3,4};
  Solution solut;
  vector<int> result = solut.productExceptSelf(input);
  vector<int> target = {24,12,8,6};
  EXPECT_EQ(target, result);
}

TEST(XXXTest, Case2){
  vector<int> input = {-1,1,0,-3,3};
  Solution solut;
  vector<int> result = solut.productExceptSelf(input);
  vector<int> target = {0,0,9,0,0};
  EXPECT_EQ(target, result);
}


int main(int argc, char* argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}