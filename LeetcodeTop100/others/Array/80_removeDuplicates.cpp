/* 题目描述: 80_删除有序数组中的重复项
Given an integer array nums sorted in non-decreasing order, remove some duplicates in-place such that each unique element appears at most twice. The relative order of the elements should be kept the same.
给定一个按非降序排序的整数数组 nums，就地删除一些重复项，使得每个唯一元素最多出现两次。元素的相对顺序应保持不变。

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array nums. More formally, if there are k elements after removing the duplicates, then the first k elements of nums should hold the final result. It does not matter what you leave beyond the first k elements.
由于在某些语言中无法更改数组的长度，因此您必须将结果放在数组 nums 的第一部分。更正式地说，如果删除重复项后有 k 个元素，则 nums 的前 k 个元素应保存最终结果。前 k 个元素之后留下什么并不重要。


Return k after placing the final result in the first k slots of nums.
将最终结果放入 nums 的前 k 个槽中，返回 k。

Do not allocate extra space for another array. You must do this by modifying the input array in-place with O(1) extra memory.
不要为另一个数组分配额外的空间。您必须通过使用 O(1) 额外内存就地修改输入数组来执行此操作。


Example 1:
Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

Example 2:
Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      //使用快慢指针的方法，其中慢指针 i 代表了新数组的末尾，快指针 j 用于遍历整个数组。
      if(nums.size()<=2) return nums.size();

      int i=2;
      for(int j = 2; j<nums.size(); j++){
        if(nums[j] != nums[ i-2]){
          nums[i++] = nums[j];
        }
      }
      return i;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> input = {1,1,1,2,2,3};
    vector<int> target = {1,1,2,2,3};
    EXPECT_EQ(5, solut.removeDuplicates(input));
    vector<int>::const_iterator first = input.begin();
    vector<int>::const_iterator last  = input.begin() + 5;
    vector<int> result(first, last);
    EXPECT_EQ(target, result);
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> input = {0,0,1,1,1,1,2,3,3};
    vector<int> target = {0,0,1,1,2,3,3};
    EXPECT_EQ(7, solut.removeDuplicates(input));
    vector<int>::const_iterator first = input.begin();
    vector<int>::const_iterator last  = input.begin() + 7;
    vector<int> result(first, last);
    EXPECT_EQ(target, result);
}


int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
