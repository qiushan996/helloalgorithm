/* 题目描述: 350_两个数组的交集
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.


Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      //方法1: 哈希表
      //方法2: 双指针
      //排序
      sort(nums1.begin(), nums1.end());
      sort(nums2.begin(), nums2.end());

      //用两个指针分别遍历两个数组
      int first=0, second=0;
      vector<int> result;
      while (first < nums1.size() && second<nums2.size())
      {
        //如果frits == second, 追加到结果中，向前移动
        if(nums1[first] == nums2[second]) {
          result.push_back(nums1[first]);
          first++;
          second++;
        }
        //如果first>second, 移动second
        else if(nums1[first]>nums2[second]) second++;
        //如果first<second, 移动first
        else first++;
      }
    return result;
  }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> n1 = {1,2,2,1};
    vector<int> n2 = {2,2};
    vector<int> target = {2,2};
    EXPECT_EQ(target, solut.intersect(n1, n2));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> n1 = {4,9,5};
    vector<int> n2 = {9,4,9,8,4};
    vector<int> target = {4, 9};
    EXPECT_EQ(target, solut.intersect(n1, n2));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
