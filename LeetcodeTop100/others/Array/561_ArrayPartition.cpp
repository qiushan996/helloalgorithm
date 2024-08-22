/* 题目描述: 561_数组拆分
Given an integer array nums of 2n integers, group these integers into n pairs (a1, b1), (a2, b2), ..., (an, bn) such that the sum of min(ai, bi) for all i is maximized. Return the maximized sum.

 

Example 1:

Input: nums = [1,4,3,2]
Output: 4
Explanation: All possible pairings (ignoring the ordering of elements) are:
1. (1, 4), (2, 3) -> min(1, 4) + min(2, 3) = 1 + 2 = 3
2. (1, 3), (2, 4) -> min(1, 3) + min(2, 4) = 1 + 2 = 3
3. (1, 2), (3, 4) -> min(1, 2) + min(3, 4) = 1 + 3 = 4
So the maximum possible sum is 4.
Example 2:

Input: nums = [6,2,6,5,1,2]
Output: 9
Explanation: The optimal pairing is (2, 1), (2, 5), (6, 6). min(2, 1) + min(2, 5) + min(6, 6) = 1 + 2 + 6 = 9.
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
      vector<std::pair<int, int>> result;
      int len = nums.size();
      sort(nums.begin(), nums.end());
      // //分组
      // for (size_t i = 0; i < nums.size(); i+=2)
      // {
      //   result.push_back(std::make_pair(nums[i], nums[i+1]));
      // }
      
      // //最小值求和
      // int min = 0;
      // for(int i=0; i<result.size(); i++){
      //   std::cout<<result[i].first<<" ,"<<result[i].second<<"\n";
      //   min += std::min(result[i].first, result[i].second);
      // }
      // return min;

      int sum =0;
      for(int i =0; i<nums.size();i+=2){
        sum +=nums[i];
      }
      return sum;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> nums = {1,4,3,2};
    EXPECT_EQ(4, solut.arrayPairSum(nums));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> nums = {6,2,6,5,1,2};
    EXPECT_EQ(9, solut.arrayPairSum(nums));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
