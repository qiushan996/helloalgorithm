/*题目描述; 154_寻找旋转排序数组中的最小值
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:

[4,5,6,7,0,1,4] if it was rotated 4 times.
[0,1,4,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.

You must decrease the overall operation steps as much as possible.

Example 1:
Input: nums = [1,3,5]
Output: 1

Example 2:
Input: nums = [2,2,2,0,1]
Output: 0
*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
      int left =0, right = nums.size()-1;
      while (left < right)
      {
        int mid = right;
        if(nums[left] <nums[mid]) right = mid -1;
        else if(nums[left]>nums[mid]) left  += 1;
        else{
          left  += 1;
        }
      }
      std::cout<<"left: "<<left<<"  right: "<<right<<std::endl;
      return nums[left];
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> nums = {1,3,5};
    EXPECT_EQ(1, solut.findMin(nums));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> nums = {2,2,2,0,1};
    EXPECT_EQ(0, solut.findMin(nums));
}
TEST(XXXTest, Case3){
    Solution solut;
    vector<int> nums = {1,2,1};
    EXPECT_EQ(1, solut.findMin(nums));
}
int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
