/* 题目描述: 169_多数元素

Given an array nums of size n, return the majority element.
给定一个大小为 n 的数组 nums，返回多数元素。
The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
众数元素是出现次数超过 ⌊n / 2⌋ 次的元素。你可以假设众数元素始终存在于数组中。

Example 1:
Input: nums = [3,2,3]
Output: 3


Example 2:
Input: nums = [2,2,1,1,1,2,2]
Output: 2
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
      //Boyer-Moore 投票算法
      int count = 0;     // 候选元素
      int candidate = 0; // 计数器

      //遍历元素，更新计数器
      for(int num: nums){
        //如果计数器为0，更换候选人
        if(count == 0){
          candidate = num;
        }
        //这行代码的目的是根据当前元素与候选元素是否相同来更新计数器。
        count += (num == candidate) ? 1: -1;
      }
      return candidate;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> input = {3,2,3};
    EXPECT_EQ(3, solut.majorityElement(input));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> input = {2,2,1,1,1,2,2};
    EXPECT_EQ(2, solut.majorityElement(input));
}

TEST(XXXTest, Case3){
    Solution solut;
    vector<int> input = {3,3,4};
    EXPECT_EQ(3, solut.majorityElement(input));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
