/* 题目描述: 78_子集
Given an integer array nums of unique elements, return all possible subsets(the power set).
给一个整数数组，各个元素唯一。返回所有kennel的子集。

The solution set must not contain duplicate subsets. Return the solution in any order.
答案中一定不能包含重复子集，顺序不限。

与No.46 不同的是，自己元素长度不固定。

Example 1:
Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]

Example 2:
Input: nums = [0]
Output: [[],[0]]


*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    int n = nums.size();
    int subset_count = 1 << n;

    for(int i=0; i < subset_count; i++){
      vector<int> subset ;
      for(int j=0; j < n; j++){
        if((i & (1<<j))!=0){
          subset.push_back(nums[j]);
        }
      }
      result.push_back(subset);
    }
    return result;
    }
};

//测试用例
TEST(XXXTest, Case1){
  vector<int> input = {1,2,3};
  vector<vector<int>> target = {{},{1},{2},{3},{1,2},{1,3},{2,3},{1,2,3}};
  Solution solut;
  EXPECT_EQ( target, solut.subsets(input));
}

TEST(XXXTest, Case2){
  vector<int> input = {0};
  vector<vector<int>> target = {{},{0}};
  Solution solut;
  EXPECT_EQ( target, solut.subsets(input));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
