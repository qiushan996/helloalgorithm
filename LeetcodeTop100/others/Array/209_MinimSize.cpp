/* 题目描述: 209_长度最小的子数组
Given an array of positive integers nums and a positive integer target, return the minimal length of a 
subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
给定一个正整数数组 nums 和一个正整数 target，返回一个子数组的最小长度，该子数组的和大于或等于 target。如果不存在这样的子数组，则返回 0。

Example 1:
Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.

Example 2:
Input: target = 4, nums = [1,4,4]
Output: 1

Example 3:
Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0
*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      // //方法1： 暴力枚举 时间复杂度O(n^2)
      // int n = nums.size();
      // int minLength = INT_MAX; // 初始化最小长度为最大值

      // // 暴力破解法：遍历所有可能的子数组
      // for (int start = 0; start < n; ++start) {
      //     int sum = 0;
      //     for (int end = start; end < n; ++end) {
      //         sum += nums[end];
      //         // 如果当前子数组的和大于或等于 target，更新最小长度
      //         if (sum >= target) {
      //             minLength = min(minLength, end - start + 1);
      //             break; // 找到满足条件的最短子数组后可以直接退出当前循环
      //         }
      //     }
      // }

      // // 如果 minLength 没有被更新，说明没有找到符合条件的子数组
      // return (minLength == INT_MAX) ? 0 : minLength;

      //滑动窗口: 不定长度
      //算法时间复杂度: O(n)
      int left =0, right = 0;
      int len = nums.size();
      int winsum = 0, ans= len+1;
      while (right<len)
      {
        winsum +=nums[right]; //求窗口的和

        //当子窗口的和满足条件时
        while (winsum >=target)
        {
          ans = min(ans, right - left +1);  //跟新子数组最小长度
          winsum -=nums[left];   //窗口向右移动
          left+=1;
        }
        right+=1;
      }
      return ans==len+1 ? 0: ans;

    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> nums = {2,3,1,2,4,3};
    EXPECT_EQ(2, solut.minSubArrayLen(7, nums));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> nums = {1,4,4};
    EXPECT_EQ(1, solut.minSubArrayLen(4, nums));
}

TEST(XXXTest, Case3){
    Solution solut;
    vector<int> nums = {1,1,1,1,1,1,1,1};
    EXPECT_EQ(0, solut.minSubArrayLen(11, nums));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
