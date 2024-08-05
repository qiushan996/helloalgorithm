/* 题目解析: 46_全排列
Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

给一个没有重复元素的整数数组。返回所有可能的排列。顺序不限
 
Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]

Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]

Example 3:
Input: nums = [1]
Output: [[1]]
*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> result ;
      backtrack(nums,0, result);
      return result;
    }
private:
  void backtrack(vector<int>& nums, int start, vector<vector<int>>& result){
    if(start == nums.size()){
      //终止条件
      result.push_back(nums);
      return ;
    }

    for(int i = start; i<nums.size(); i++){
      swap(nums[start], nums[i]);
      backtrack(nums, start + 1, result);
      swap(nums[start], nums[i]);  
    }
  }
};

//测试用例
TEST(XXXTest, Case1){
  vector<int> input = {1,2,3};
  vector<vector<int>> target = {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
  Solution solut;
  EXPECT_EQ( target, solut.permute(input) );
}

TEST(XXXTest, Case2){
  vector<int> input = {0,1};
  vector<vector<int>>target = {{0, 1},{1,0}};
  Solution solut;
  EXPECT_EQ( target, solut.permute(input) );
}

TEST(XXXTest, Case3){
  vector<int> input = {1};
  vector<vector<int>> target = {{1}};
  Solution solut;
  EXPECT_EQ( target, solut.permute(input) );
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
