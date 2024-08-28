/* 题目描述: 1343_大小为K且平均值大于等于阈值的子数组数

Given an array of integers arr and two integers k and threshold, return the number of sub-arrays of size k and average greater than or equal to threshold.
给定一个整数数组 arr 和两个整数 k 和阈值，返回大小为 k 且平均值大于或等于阈值的子数组的数量。
 

Example 1:
Input: arr = [2,2,2,2,5,5,5,8], k = 3, threshold = 4
Output: 3
Explanation: Sub-arrays [2,5,5],[5,5,5] and [5,5,8] have averages 4, 5 and 6 respectively. All other sub-arrays of size 3 have averages less than 4 (the threshold).

Example 2:
Input: arr = [11,13,17,23,29,31,7,5,2,3], k = 3, threshold = 5
Output: 6
Explanation: The first 6 sub-arrays of size 3 have averages greater than 5. Note that averages are not integers.
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
      //滑动窗口
      int left =0, right =0;
      int len = arr.size();
      int winsum = 0;    //窗口和
      int count = 0;     //统计子数组计数

      while (right<len)
      {
        winsum +=arr[right]; //当size小于窗口时，移动元素并求和

        //当size等于窗口大小时，判断是否满足题目限定条件
        if(right - left +1 >=k){
          //求平均值
          if(winsum >=k * threshold) count++;
          winsum -=arr[left];
          left++;
        }

        right++;
      }
      return count;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> nums = {2,2,2,2,5,5,5,8};
    EXPECT_EQ(3, solut.numOfSubarrays(nums, 3, 4));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> nums = {11,13,17,23,29,31,7,5,2,3};
    EXPECT_EQ(6, solut.numOfSubarrays(nums, 3, 5));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
