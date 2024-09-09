/*题目描述: 40_组合总和II

归类： 数组、回溯

Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sum to target.

Each number in candidates may only be used once in the combination.

Note: The solution set must not contain duplicate combinations.

Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: 
[
[1,1,6],
[1,2,5],
[1,7],
[2,6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5
Output: 
[
[1,2,2],
[5]
]
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
      //回溯算法
      // 1.	排序：首先对数组进行排序，这有助于后面的剪枝和避免重复。
      // 2.	回溯：使用回溯法枚举所有可能的组合。
      // •	遍历数组中的每个数字，将其加入当前组合中，并递归地寻找剩余的目标值。
      // •	每次从数组的当前位置向后查找，避免重复使用数字。
      // •	如果当前数字已经大于剩余的目标值，则终止递归。
      // •	如果数字重复出现，在这一层递归中跳过相同的数字，以避免产生重复的组合。

      vector<vector<int>> result;
      vector<int> current;
      sort(candidates.begin(), candidates.end());
      backtrack(candidates, target, 0,current, result);
      return result;

    }

    void backtrack(vector<int>& candidates, int target, int start, vector<int>&path, vector<vector<int>>& res){
      if(target == 0){
        res.push_back(path);
        return;
      }

      for (int  i = start; i < candidates.size() && target - candidates[i]>=0; i++)
      {
        if(i>start && candidates[i] == candidates[i-1]) continue;
        path.push_back(candidates[i]);
        backtrack(candidates, target-candidates[i], i+1, path, res);
        path.pop_back();
      }
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> nums = {10,1,2,7,6,1,5};
    vector<vector<int>> target = {
        {1,1,6},
        {1,2,5},
        {1,7},
        {2,6}
    };

    EXPECT_EQ(target, solut.combinationSum2(nums, 8));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> nums = {2,5,2,1,2};
    vector<vector<int>> target = {
        {1,2,2},
        {5}
    };

    EXPECT_EQ(target, solut.combinationSum2(nums, 5));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
