/* 题目描述: 31_下一个排列

A permutation of an array of integers is an arrangement of its members into a sequence or linear order.
整数数组的排列是将其成员排列成序列或线性顺序。

For example, for arr = [1,2,3], the following are all the permutations of arr: [1,2,3], [1,3,2], [2, 1, 3], [2, 3, 1], [3,1,2], [3,2,1].

Example 1:
Input: nums = [1,2,3]
Output: [1,3,2]

Example 2:
Input: nums = [3,2,1]
Output: [1,2,3]

Example 3:
Input: nums = [1,1,5]
Output: [1,5,1]
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
      int n = nums.size(), i, j;
      for(i = n-2; i>=0; i--){
        if(nums[i]<nums[i+1]) break;
      }  

      if(i >=0){
        for(j = n - 1; j > i; j--){
          if(nums[j] > nums[i])break;
        }
        std::swap(nums[i], nums[j]);
      }

      std::reverse(nums.begin() + i + 1, nums.end());
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> input = {1,2,3};
    vector<int> target = {1,3,2};
    solut.nextPermutation(input);
    EXPECT_EQ(target, input);
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> input = {3,2,1};
    vector<int> target = {1,2,3};
    solut.nextPermutation(input);
    EXPECT_EQ(target, input);
}

TEST(XXXTest, Case3){
    Solution solut;
    vector<int> input = {1,1,5};
    vector<int> target = {1,5,1};
    solut.nextPermutation(input);
    EXPECT_EQ(target, input);
}
int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
