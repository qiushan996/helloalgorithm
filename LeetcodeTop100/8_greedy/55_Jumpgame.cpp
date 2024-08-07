/*
You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.


Example 1:
Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:
Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
      int maxReach = 0;
      for(int i = 0; i <= maxReach && i< nums.size(); i++){
        maxReach = max(maxReach, i + nums[i]);
        if(maxReach >= nums.size() - 1){
          return true;
        }
      }
      return false;    
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> input = {2,3,1,1,4};
    EXPECT_TRUE(solut.canJump(input));
}
TEST(XXXTest, Case2){
    Solution solut;
    vector<int> input = {3,2,1,0,4};
    EXPECT_FALSE(solut.canJump(input));
}



int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
