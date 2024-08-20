/* 题目描述: 724_寻找数组的中心下标

Given an array of integers nums, calculate the pivot index of this array.
给定一个整数数组 nums，计算该数组的枢轴索引。

The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
枢轴指数是指指数左侧所有数字的总和等于指数右侧所有数字的总和的指数。

If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
如果索引位于数组的左边缘，则左侧总和为 0，因为左侧没有元素。这也适用于数组的右边缘。

Return the leftmost pivot index. If no such index exists, return -1.

Example 1:
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11

Example 2:
Input: nums = [1,2,3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.

Example 3:
Input: nums = [2,1,-1]
Output: 0
Explanation:
The pivot index is 0.
Left sum = 0 (no elements to the left of index 0)
Right sum = nums[1] + nums[2] = 1 + -1 = 0
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    //通过计算总和然后迭代数组来解决。先计算整个数组的总和，然后遍历数组，使用一个变量来维护从开始到当前索引的元素总和（即左侧和）。
    //通过左侧和和总和可以计算右侧和，然后比较左侧和和右侧和是否相等。
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int num: nums) sum+=num;
  
    //统计left的he
    int leftsum = 0;
    for(int i=0; i<nums.size(); i++){
      if(leftsum == sum-leftsum - nums[i]){
        return i;
      }
      leftsum +=nums[i];
    }
    return -1;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> input = {1,7,3,6,5,6};

    EXPECT_EQ(3, solut.pivotIndex(input));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> input = {1,2,3};

    EXPECT_EQ(-1, solut.pivotIndex(input));
}

TEST(XXXTest, Case3){
    Solution solut;
    vector<int> input = {2,1,-1};

    EXPECT_EQ(0, solut.pivotIndex(input));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
