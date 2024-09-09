/* 题目描述:  77_组合
Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].

You may return the answer in any order.

Example 1:
Input: n = 4, k = 2
Output: [[1,2],[1,3],[1,4],[2,3],[2,4],[3,4]]
Explanation: There are 4 choose 2 = 6 total combinations.
Note that combinations are unordered, i.e., [1,2] and [2,1] are considered to be the same combination.
Example 2:

Input: n = 1, k = 1
Output: [[1]]
Explanation: There is 1 choose 1 = 1 total combination.
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
      //回溯算法
      vector<vector<int>> res;
      vector<int> current;
      int path;
      backtrack(res, current, 0, n, k);
      return res;

    }
    void backtrack(vector<vector<int>>& res, vector<int>& current, int start, int n, int k){
      if(current.size()==k){
        res.push_back(current);
        return;
      }
      for(int i = start; i<n; i++){
        if(current.size()<k) current.push_back(i+1);
        backtrack(res, current, i+1, n,k);
        current.pop_back();
      }
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<vector<int>> target = {{{1,2},{1,3},{1,4},{2,3},{2,4},{3,4}}};
    EXPECT_EQ(target, solut.combine(4, 2));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<vector<int>> target = {{1}};
    EXPECT_EQ(target, solut.combine(1, 1));
}


int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
