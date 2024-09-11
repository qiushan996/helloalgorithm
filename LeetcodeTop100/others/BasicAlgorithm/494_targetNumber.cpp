/* 题目描述: 494_目标之和

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.

Example 1:
Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3

Example 2:
Input: nums = [1], target = 1
Output: 1
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
      // 1.	从第一个数字开始，递归地尝试每种可能的符号（加或减）。
      // 2.	对于每个数字，有两种选择：
      // •	加上这个数字。
      // •	减去这个数字。
      // 3.	如果在递归的最深层（处理完所有数字），currentSum 等于 target，增加解的计数。
      // 4.	回溯到上一层，尝试另一种选择。

      int count = 0;
      backtrack(nums, target,0, 0, count);
      return count;
    }

    void backtrack(vector<int>& nums, int target, int index, int currentSum, int& count){
      if(index == nums.size()){
        if(currentSum == target){
          count++;
        }
      }else{
          backtrack(nums,target,index+1, currentSum+nums[index],  count);
          backtrack(nums,target,index+1, currentSum-nums[index], count);
        }
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> num = {1,1,1,1,1};
    EXPECT_EQ(5, solut.findTargetSumWays(num, 3));
}
TEST(XXXTest, Case2){
    Solution solut;
    vector<int> num = {1 };
    EXPECT_EQ(1, solut.findTargetSumWays(num, 1));
}


int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
