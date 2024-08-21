/*题目描述: 485_最大连续1的个数

Given a binary array nums, return the maximum number of consecutive 1's in the array.
Example 1:
Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.

Example 2:
Input: nums = [1,0,1,1,0,1]
Output: 2
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      // int maxone = 0;
      // int tempcount = 0;
      // for(int i=0; i<nums.size(); i++){      
      //   if(nums[i]==1) tempcount++;
      //   else tempcount=0;
      //   maxone = max(maxone, tempcount);
      // }
      // return maxone;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> input = {1,1,0,1,1,1};
    EXPECT_EQ(3, solut.findMaxConsecutiveOnes(input));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> input = {1,0,1,1,0,1};
    EXPECT_EQ(2, solut.findMaxConsecutiveOnes(input));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
