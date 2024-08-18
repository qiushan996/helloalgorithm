/* 题目描述; 75_颜色排序
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.


Example 1:
Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]


Example 2:
Input: nums = [2,0,1]
Output: [0,1,2]
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        // 该问题耶称为荷兰国旗问题，对应的解决方案是三指针法
        int low = 0, mid = 0;
        int high = nums.size() - 1;

        while (mid <= high)
        {
          switch (nums[mid])
          {
          case 0:
            std::swap(nums[low++], nums[mid++]);
            break;
          case 1:
            mid++;
            break;
          case 2:
            std::swap(nums[mid], nums[high--]);
            break;
          }
        }
        
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> nums = {2,0,2,1,1,0};
    vector<int> target = {0,0,1,1,2,2};
    solut.sortColors(nums);
    EXPECT_EQ(target, nums);
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> nums = {2,0,1};
    vector<int> target = {0,1,2};
    solut.sortColors(nums);
    EXPECT_EQ(target, nums);
}


int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
