/* 题目描述: 47_全排列II(有重复元素)
Given a collection of numbers, nums, that might contain duplicates, return all possible unique permutations in any order.

Example 1:
Input: nums = [1,1,2]
Output:
[[1,1,2],
 [1,2,1],
 [2,1,1]]
Example 2:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
      // 方法：回溯 + 排序
      // 1.	排序：首先对数组进行排序，这样可以方便后面的重复检测。
      // 2.	定义回溯函数：使用一个临时列表来存储当前的排列内容。
      // 3.	使用标记数组：通过一个布尔数组 used 来标记哪些数字已经被使用过，防止重复使用。
      // 4.	递归条件：当临时列表的长度等于原列表的长度时，将其加入结果列表。
      // 5.	剪枝条件：如果当前元素与前一个元素相同，并且前一个元素未被使用过，说明当前分支会产生重复结果，应该跳过。
      vector<vector<int>>  res;
      vector<int> tmp;
      vector<bool> used(nums.size(), false);
      vector<int> current;
      //排序
      sort(nums.begin(), nums.end());
      backtrack(nums, used,tmp, res);
      return res;
    }


    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& temp, vector<vector<int>>& res ){
      //通No.78(没有重复元素的全排列) 
      //需要考虑如何避免重复项：
      if(temp.size() == nums.size()){
        res.push_back(temp);
        return;
      }

      for(int i=0; i<nums.size(); i++){
        //剪支操作
        if(used[i] || (i>0)&&nums[i]==nums[i-1]&&!used[i-1]) continue;
        used[i] =  true;
        temp.push_back(nums[i]);
        backtrack(nums, used,temp, res);
        used[i] = false;
        temp.pop_back();
      }
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> nums = {1,1,2};
    vector<vector<int>> target = {{1,1,2},{1,2,1},{2,1,1}};
    EXPECT_TRUE(areEqualUnordered(target, solut.permuteUnique(nums)));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> nums = {1,2,3};
    vector<vector<int>> target = {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
    EXPECT_TRUE(areEqualUnordered(target, solut.permuteUnique(nums)));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
