/*题目描述: 448_找到所有数组中消失的数字
Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

Example 1:

Input: nums = [4,3,2,7,8,2,3,1]
Output: [5,6]
Example 2:

Input: nums = [1,1]
Output: [2]
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      //	1.	标记存在的数字：遍历数组，对于每个数字，将对应索引位置的数字标记为负数（如果还未被标记）。这样做不会改变数字的绝对值，因此不会影响对该数字的判断。
      // •	使用 abs(nums[i]) - 1 作为索引，因为数组索引从 0 开始而数字从 1 开始。
      // •	如果数字已经是负数，表示之前已经访问过这个位置。
      // 2.	查找未标记的索引：第二次遍历数组，查找所有值仍为正数的索引，这些索引+1对应的数字就是未出现在数组中的数字。
      vector<int> result;
      for(int i=0; i<nums.size(); i++){
        int index = abs(nums[i])-1;
        if(nums[index] > 0){
          nums[index] = -nums[index];
        }
      }
      for(int i=0; i<nums.size(); i++){
        if(nums[i]>0) result.push_back(i+ 1);
      }
      return result;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> target = {5,6};
    EXPECT_EQ(target, solut.findDisappearedNumbers(nums));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> nums = {1,1};
    vector<int> target = {2};
    EXPECT_EQ(target, solut.findDisappearedNumbers(nums));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
