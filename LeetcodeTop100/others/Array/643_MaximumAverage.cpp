/*题目描述: 643_子数组最大平均数
You are given an integer array nums consisting of n elements, and an integer k.
Find a contiguous subarray whose length is equal to k that has the maximum average value and return this value. Any answer with a calculation error less than 10-5 will be accepted.
给定一个由 n 个元素组成的整数数组 nums 和一个整数 k。
查找一个长度等于 k ​​且具有最大平均值的连续子数组并返回该值。任何计算误差小于 10-5 的答案都将被接受。

Example 1:
Input: nums = [1,12,-5,-6,50,3], k = 4
Output: 12.75000
Explanation: Maximum average is (12 - 5 - 6 + 50) / 4 = 51 / 4 = 12.75

Example 2:
Input: nums = [5], k = 1
Output: 5.00000
*/
#include<vector>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
      //
      if(k==0 || nums.size()==0)return double(nums[0]);
      //滑动窗口：定长
      int left =0, right = 0;
      double maxavrage =  -DBL_MAX;  //初识化为最小值，不应该是0
      int subsum =0;
      while (right<nums.size())
      {   
        subsum += nums[right];
        if((right-left +1)==k){
          //double tempavg = subsum*1.00 / k;
          double tempavg = static_cast<double>(subsum) / k;
          maxavrage =std::max(maxavrage, tempavg);  // 更新平均最大值
          subsum -=nums[left];
          left +=1;
        }
        right++;
      }
      return round(maxavrage * 100000) / 100000.0;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> nums = {1,12,-5,-6,50,3};
    EXPECT_EQ(12.75000, solut.findMaxAverage(nums, 4));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> nums = {5};
    EXPECT_EQ(5.000000, solut.findMaxAverage(nums, 1));
}

TEST(XXXTest, Case3){
    Solution solut;
    vector<int> nums = {-1};
    EXPECT_EQ(-1.00000, solut.findMaxAverage(nums, 1));
}

TEST(XXXTest, Case4){
    Solution solut;
    vector<int> nums = {0,4,0,3,2};
    EXPECT_EQ(4.00000, solut.findMaxAverage(nums, 1));
}

TEST(XXXTest, Case5){
    Solution solut;
    vector<int> nums = {8860,-853,6534,4477,-4589,8646,-6155,-5577,-1656,-5779,-2619,-8604,-1358,-8009,4983,7063,3104,-1560,4080,2763,5616,-2375,2848,1394,-7173,-5225,-8244,-809,8025,-4072,-4391,-9579,1407,6700,2421,-6685,5481,-1732,-8892,-6645,3077,3287,-4149,8701,-4393,-9070,-1777,2237,-3253,-506,-4931,-7366,-8132,5406,-6300,-275,-1908,67,3569,1433,-7262,-437,8303,4498,-379,3054,-6285,4203,6908,4433,3077,2288,9733,-8067,3007,9725,9669,1362,-2561,-4225,5442,-9006,-429,160,-9234,-4444,3586,-5711,-9506,-79,-4418,-4348,-5891};

    EXPECT_EQ(-594.58065, solut.findMaxAverage(nums, 93));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
