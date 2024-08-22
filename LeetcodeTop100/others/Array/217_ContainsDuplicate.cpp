/* 题目描述: 217_存在重复元素
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

 

Example 1:
Input: nums = [1,2,3,1]
Output: true
Example 2:

Input: nums = [1,2,3,4]
Output: false
Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
      //sort(nums.begin(), nums.end());
      unordered_map<int,int> input;
      for(int i = 0; i<nums.size(); i++){
        input[nums[i]] +=1;
        if (input[nums[i]]>=2)
        {
           return true;
        }  
      }
      // for (size_t i = 0; i < nums.size(); i++)
      // {
      //   if(input[nums[i]]>=2) return true;
      // }
      return false;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int>  nums = {1,2,3,1};
    EXPECT_TRUE(solut.containsDuplicate(nums));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int>  nums = {1,2,3,4};
    EXPECT_FALSE(solut.containsDuplicate(nums));
}

TEST(XXXTest, Case3){
    Solution solut;
    vector<int>  nums = {1,1,1,3,3,4,3,2,4,2};
    EXPECT_TRUE(solut.containsDuplicate(nums));
}
int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
