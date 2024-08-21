/* 题目描述： 15 三数之和

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.
Notice that the solution set must not contain duplicate triplets.

给定一个整数数组，返回所有三个数相加为0的数，要求三个数不相同。
注意：解决方案不包含重复的三元组

Example 1:
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.

Example 2:
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.

Example 3:
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.

*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result ;
        int len =nums.size();

        sort(nums.begin(), nums.end());

        for (size_t i = 0; i < len-2; i++)
        {
          if(i>0&&nums[i]==nums[i-1]) continue;

          int left = i+1;
          int right = len-1;

          while (left<right)
          {
            int sum = nums[left] + nums[i] + nums[right];
            if(sum == 0){
              result.push_back({nums[left], nums[i], nums[right]});

              while(left<right&&nums[left]==nums[left+1]) left++;
              while(left<right&&nums[right]==nums[right-1]) right--;

              left++;
              right--;
            }
            else if(sum<0) left++;
            else right--;
          }
        }
      return result;  
    }
};

//自定义一个比较两个vector<vector<int>>  变量的函数，然后使用EXPECT_TRUE、ASSERT_TRUE来判断
bool CompareVector(vector<vector<int>> res1, vector<vector<int>> res2){
  if(res1.size()!=res2.size()) return false;

  //vector内部排序
  for(auto& v1:res1) sort(v1.begin(), v1.end());
  for(auto& v2:res2) sort(v2.begin(), v2.end());

  //vector外部排序
  sort(res1.begin(), res1.end());
  sort(res2.begin(), res2.end());

  return res1==res2;
}

TEST(Sum3Test, case1){
  vector<int> input1 = {-1,0,1,2,-1,-4};
  vector<vector<int>> target = {{-1,-1,2},{-1,0,1}};

  Solution solut;
  vector<vector<int>> result = solut.threeSum(input1);

  EXPECT_TRUE(CompareVector(target, result));
}

TEST(Sum3Test, case2){
  vector<int> input1 = {0,1,1};
  vector<vector<int>> target = {};

  Solution solut;
  vector<vector<int>> result = solut.threeSum(input1);
  EXPECT_TRUE(CompareVector(target, result));
}

TEST(Sum3Test, case3){
  vector<int> input1 = {0,0,0};
  vector<vector<int>> target = {{0,0,0}};

  Solution solut;
  vector<vector<int>> result = solut.threeSum(input1);

   EXPECT_TRUE(CompareVector(target, result));
}


int main(int argc, char* argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}