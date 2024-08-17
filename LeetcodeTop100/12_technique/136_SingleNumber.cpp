/* 题目描述: 136_只出现一次的数字

Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.
给定一个非空整数数组 nums，除一个元素外，其他每个元素都出现了两次。找出那个元素。

You must implement a solution with a linear runtime complexity and use only constant extra space.
您必须实现具有线性运行时间复杂度的解决方案并且仅使用恒定的额外空间。

Example 1:
Input: nums = [2,2,1]
Output: 1

Example 2:
Input: nums = [4,1,2,1,2]
Output: 4

Example 3:
Input: nums = [1]
Output: 1

*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
      //知识点: 异或运算
      //任何数和0做异或运算，结果仍然是原来的数
      //任何数和其自身做异或运算，结果是0，
      //异或运算满足交换律和结合律
      int result = 0;
      for(int num: nums){
        result ^=num;
      }
      return result;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> input = {2,2,1};
    EXPECT_EQ(1, solut.singleNumber(input));
}

//测试用例
TEST(XXXTest, Case2){
    Solution solut;
    vector<int> input = {4,1,2,1,2};
    EXPECT_EQ(4, solut.singleNumber(input));
}

//测试用例
TEST(XXXTest, Case3){
    Solution solut;
    vector<int> input = {1};
    EXPECT_EQ(1, solut.singleNumber(input));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
