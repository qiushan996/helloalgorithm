/* 题目描述: 560_和为K的字数组

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
给定一个整数数组 nums 和一个整数 k，返回和等于 k ​​的子数组的总数。

A subarray is a contiguous non-empty sequence of elements within an array.
子数组是数组内连续的非空元素序列。

Example 1:
Input: nums = [1,1,1], k = 2
Output: 2


Example 2:
Input: nums = [1,2,3], k = 3
Output: 2
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      unordered_map<int, int> sumFreq;
      sumFreq[0] = 1;

      int count = 0;
      int sum = 0;

      for(int num: nums){
        sum += num;
        if(sumFreq.find(sum - k) != sumFreq.end()){
          count += sumFreq[sum -k];
        }
        sumFreq[sum]++;
      }

      return count;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> input = {1,1,1};
    int result = solut.subarraySum(input, 2);
    EXPECT_EQ(2, result);
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> input = {1,2,3};
    int result = solut.subarraySum(input,3);
    EXPECT_EQ(2, result);
}



int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
