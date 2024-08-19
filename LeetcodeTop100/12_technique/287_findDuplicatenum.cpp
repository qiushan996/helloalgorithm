/* 题目描述: 287_寻找重复数

Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
给定一个整数数组 nums，其中包含 n + 1 个整数，其中每个整数都在 [1, n] 范围内（包括 1, n）。

There is only one repeated number in nums, return this repeated number.

You must solve the problem without modifying the array nums and uses only constant extra space.

 

Example 1:
Input: nums = [1,3,4,2,2]
Output: 2

Example 2:
Input: nums = [3,1,3,4,2]
Output: 3

Example 3:
Input: nums = [3,3,3,3,3]
Output: 3
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:    
      int findDuplicate(vector<int>& nums) {
      //Floyd's Tortoise and Hare (Cycle Detection) 算法
      // //该方法主要用来检测链表中的环
      // 此算法包含两个阶段：
      //1.快慢指针寻找相遇点：使用两个指针，一个移动速度是另一个的两倍。由于存在重复，那么在数组的索引和值之间必然形成了一个环，快慢指针最终会在环内相遇。
      //2.找到环的入口：找到快慢指针相遇点后，将其中一个指针放回起点，然后两个指针以相同速度移动，再次相遇的地点即为环的入口，也就是重复的数字。

      int tortoise = nums[0];
      int hare = nums[0];

      do{
        tortoise = nums[tortoise];
        hare = nums[nums[hare]];
      }while(tortoise != hare);

      tortoise = nums[0];
      while (tortoise != hare)
      {
        tortoise = nums[tortoise];
        hare = nums[hare];
      }
      return hare;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> nums = {1,3,4,2,2};
    EXPECT_EQ(2, solut.findDuplicate(nums));
}
TEST(XXXTest, Case2){
    Solution solut;
    vector<int> nums = {3,1,3,4,2};
    EXPECT_EQ(3, solut.findDuplicate(nums));
}

TEST(XXXTest, Case3){
    Solution solut;
    vector<int> nums = {3,3,3,3};
    EXPECT_EQ(3, solut.findDuplicate(nums));
}
int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
