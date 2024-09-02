/* 题目描述: 78_子集
回溯算法

Given an integer array nums of unique elements, return all possible subsets(the power set).

The solution set must not contain duplicate subsets. Return the solution in any order.

 
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

bool areEqualUnordered(std::vector<std::vector<int> > vec1, std::vector<std::vector<int> > vec2) {
    if (vec1.size() != vec2.size()) {
        return false;
    }

    for (auto& subvec : vec1) {
        std::sort(subvec.begin(), subvec.end());
    }

    for (auto& subvec : vec2) {
        std::sort(subvec.begin(), subvec.end());
    }

    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());

    return vec1 == vec2;
}


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
      // //回溯算法
      // 1.	初始化：创建一个全局列表来存储所有子集。
      // 2.	递归函数：
      // •	接收当前位置和一个当前构建的子集作为参数。
      // •	将当前构建的子集加入到全局列表中。
      // •	从当前位置开始，遍历输入数组。
      // •	将当前元素加入子集，递归调用函数处理下一个位置，然后撤销加入（回溯）。
      // 3.	处理边界情况：如果输入数组为空，直接返回只包含空列表的列表。
      vector<vector<int>>  res;
      vector<int> current;
      backtrack(res, nums,0, current);
      return res;
    }

    void backtrack(vector<vector<int>>& result, vector<int>& nums, int start, vector<int>& current ){
      result.push_back(current);
      for(int i =start; i<nums.size(); ++i){
        current.push_back(nums[i]);
        backtrack(result, nums, i+1, current);
        current.pop_back();
      }
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> nums = {1,2,3};
    vector<vector<int>> target = {{}, {1}, {2}, {1,2}, {3}, {1,3}, {2,3}, {1,2,3}};
    bool res = areEqualUnordered(target, solut.subsets(nums));
    EXPECT_TRUE(res);
}
//测试用例
TEST(XXXTest, Case2){
    Solution solut;
    vector<int> nums = {0};
    vector<vector<int>> target = {{}, {0}};
    bool res = areEqualUnordered(target, solut.subsets(nums));
    EXPECT_TRUE(res);
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
