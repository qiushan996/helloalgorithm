/*题目描述:  81_搜索旋转排序数组II

There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

You must decrease the overall operation steps as much as possible.
Example 1:
Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true

Example 2:
Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
      int left =0, right = nums.size()-1;
      while(left <= right){
        int mid = left + (right - left)/2;
        //找到了
        if(nums[mid] ==  target) return true;

        if(nums[left] == nums[mid] && nums[mid]== nums[right]){
          right--;
          left++;
        }
        //左边是排序
        else if(nums[left] <=nums[mid]){
            if(nums[left] <= target && target < nums[mid]){
              right = mid -1;
            }else{
              left = mid + 1;
            }
        }
        else{
          if(nums[mid]<target && target <=nums[right]){
            left = mid + 1;
          }else{
            right = mid -1;
          }
        }
      }
      return false;
    }
};


//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> nums = {2,5,6,0,0,1,2};   
    EXPECT_TRUE(solut.search(nums, 0));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> nums = {2,5,6,0,0,1,2};    
    EXPECT_FALSE(solut.search(nums, 3));
}


TEST(XXXTest, Case3){
    Solution solut;
    vector<int> nums = {1};    
    EXPECT_TRUE(solut.search(nums, 1));
}

TEST(XXXTest, Case4){
    Solution solut;
    vector<int> nums = {1,1,1,1,1,1,1,1,1,13,1,1,1,1,1,1,1,1,1,1,1,1};   
    EXPECT_TRUE(solut.search(nums, 13));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
