/* 题目描述: 349_两个数组的交集
Given two integer arrays nums1 and nums2, return an array of their 
intersection Each element in the result must be unique and you may return the result in any order.

Example 1:
Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]

Example 2:
Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.

*/
#include<vector>
#include<unordered_set>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      // 分离双指针
      // int l1 =0, l2=0;
      // int len1 = nums1.size(), len2 = nums2.size();
      // vector<int> result;
      // sort(nums1.begin(), nums1.end());
      // sort(nums2.begin(), nums2.end());
      // while (l1<len1 && l2 < len2)
      // {
      //   if(nums1[l1++] == nums2[l2++]){
      //       result.push_back(nums1[l1]);
      //   }else if(nums1[l1]<nums2[l2]) l1++;
      //   else l2++;
      // }
      // return result;

      std::sort(nums1.begin(), nums1.end());
      std::sort(nums2.begin(), nums2.end());
      
      int i = 0, j = 0;
      std::unordered_set<int> resultSet;
      
      while (i < nums1.size() && j < nums2.size()) {
          if (nums1[i] == nums2[j]) {
              resultSet.insert(nums1[i]);
              ++i;
              ++j;
          } else if (nums1[i] < nums2[j]) {
              ++i;
          } else {
              ++j;
          }
      }

      return std::vector<int>(resultSet.begin(), resultSet.end());
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> nums1 = {1,2,2,1};
    vector<int> nums2 = {2,2};
    vector<int> target = {2};
    EXPECT_EQ(target, solut.intersection(nums1, nums2));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> nums1 = {4,9,5};
    vector<int> nums2 = {9,4,9,8,4};
    vector<int> target = {9,4};
    EXPECT_EQ(target, solut.intersection(nums1, nums2));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
