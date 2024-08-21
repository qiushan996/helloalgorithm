/* 题目描述: 912_排序数组

Given an array of integers nums, sort the array in ascending order and return it.
给一个整数数组，返回降序排序后的数组
You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.
不使用任何内置函数，时间复杂度为O(nlog(n))， 最小的空间复杂度  

Example 1:
Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

Example 2:
Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessairly unique.

*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
      //希尔排序
      int len = nums.size();
      int gap = len/2;

      //按照gap分组
      while (gap >0)
      {
        //每一组元素排序
        for(int i=gap; i<len; i++){
          //每组元素中第一个元素
          int temp = nums[i];
          int j = i;
          //从右至左遍历每组中的有序数组元素
          for (j = i; j>=gap && nums[j - gap] > temp; j-=gap)
          {
            nums[j] = nums[j-gap];
          }
          nums[j] = temp;
        }
        gap = gap/2;
      }
      return nums;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> input = {5,2,3,1};
    vector<int> target = {1,2,3,5};
    EXPECT_EQ(target, solut.sortArray(input));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> input = {5,1,1,2,0,0};
    vector<int> target = {0,0,1,1,2,5};
    EXPECT_EQ(target, solut.sortArray(input));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
