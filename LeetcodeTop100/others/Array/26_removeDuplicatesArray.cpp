/*题目描述: 26_删除有序数组中的重复项

Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in nums.

Consider the number of unique elements of nums to be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the unique elements in the order they were present in nums initially. The remaining elements of nums are not important as well as the size of nums.
Return k.

Example 1:
Input: nums = [1,1,2]
Output: 2, nums = [1,2,_]
Explanation: Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [0,0,1,1,1,2,2,3,3,4]
Output: 5, nums = [0,1,2,3,4,_,_,_,_,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      //快慢指针解决
      if (nums.empty()) return 0;

      int i = 0;
      for (int j = 1; j < nums.size(); j++) {
          if (nums[j] != nums[i]) {
              i++;
              nums[i] = nums[j];
          }
      }
      return i+1 ;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> nums = {1,1,2};
    //vector<int> target = {1,2,_};
    EXPECT_EQ(2, solut.removeDuplicates(nums));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> nums = {0,0,1,1,1,2,2,3,3,4};
    //vector<int> target = {0,1,2,3,4,_,_,_,_,_};
    EXPECT_EQ(5, solut.removeDuplicates(nums));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
