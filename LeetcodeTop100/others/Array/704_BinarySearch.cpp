/*题目描述: 704_二分查找

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4

Example 2:
Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
      //方法1: 在循环中直接返回
      //   int left =0, right = nums.size() -1;
      //   while (left<=right)
      //   {
      //     //计算中间值
      //     int mid = (left + right )/2;   // mid = left + ((right -left )/2)
      //     if(target == nums[mid]) return mid;
      //     else if(target >nums[mid]) {
      //       left = mid +1;
      //     }else{
      //       right = mid-1;
      //     }
      //   }
      // return -1;

      //方法2: 跳出循环后需进一步判断
      // int left =0, right = nums.size() -1;
      // while (left < right)
      // {
      //   int mid = left + (right - left + 1)/2;
      //   if(nums[mid] >target) right = mid -1;
      //   else  left = mid;
      // }
      // std::cout<<"left: "<<left<<" right:"<<right<<std::endl;
      // return nums[left]==target ? left: -1;

      //方法3:
      int left = 0, right = nums.size()-1;
      while (left<right)
      {
        int mid = left + (right -left)/2;
        if(nums[mid]<target) left = mid + 1;
        else right = mid;
      }
      std::cout<<"left: "<<left<<" right:"<<right<<std::endl;
      return nums[right]==target ? right: -1;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> nums = {-1,0,3,5,9,12};
    EXPECT_EQ(4, solut.search(nums, 9));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> nums = {-1,0,3,5,9,12};
    EXPECT_EQ(-1, solut.search(nums, 2));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
