/* 题目解析: 39_组合总和
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.
给定一个由不同整数候选数组成的数组和一个目标整数 target，返回所有候选数的唯一组合列表，其中所选数字的总和等于 target。您可以按任何顺序返回这些组合。


The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the 
frequency of at least one of the chosen numbers is different.
可以从候选数中无限次地选择相同的数字。如果至少一个所选数字的频率不同，则两个组合是唯一的。


The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
生成的测试用例使得对于给定的输入，总和等于 target 的唯一组合数小于 150 个组合。


Example 1:
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
These are the only two combinations.


Example 2:
Input: candidates = [2,3,5], target = 8
Output: [[2,2,2,2],[2,3,3],[3,5]]


Example 3:
Input: candidates = [2], target = 1
Output: []

*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
       vector<vector<int>> result;
       vector<int> current;
       sort(candidates.begin(),candidates.end());
       backtrack(candidates, target, 0, current, result);
       return result; 
    }
private:
    void backtrack(const vector<int>& candidates, int remain, int start, vector<int>& current, vector<vector<int>>& result){
      if(remain==0){
        result.push_back(current);
        return ;
      }
      for(int i = start; i < candidates.size() && candidates[i]<=remain; i++){
        current.push_back(candidates[i]);
        backtrack(candidates, remain-candidates[i], i, current, result);
        current.pop_back();
      }
    }
};

//测试用例
TEST(XXXTest, Case1){
  vector<int> input = {2,3,6,7};
  Solution solut;
  vector<vector<int>> result = solut.combinationSum(input, 7);
  vector<vector<int>> target = {{2,2,3}, {7}};
  EXPECT_EQ(target,result );
}

TEST(XXXTest, Case2){
  vector<int> input = {2,3,5};
  Solution solut;
  vector<vector<int>> result = solut.combinationSum(input, 8);
  vector<vector<int>> target = {{2,2,2,2},{2,3,3}, {3,5}};
  EXPECT_EQ(target,result );
}

TEST(XXXTest, Case3){
  vector<int> input = {2};
  Solution solut;
  vector<vector<int>> result = solut.combinationSum(input, 1);
  vector<vector<int>> target = {};
  EXPECT_EQ(target,result );
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
