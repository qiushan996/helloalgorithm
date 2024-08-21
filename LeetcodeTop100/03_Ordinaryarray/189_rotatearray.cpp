/* 题目描述  189_轮转数组_RotateArray

Given an integer array nums, rotate the array to the right by k steps, where k is non-negative.

对于给定的一个整数数组，将数组向右转转K步，其中k为非负数。
 
Example 1:
Input: nums = [1,2,3,4,5,6,7], k = 3
Output: [5,6,7,1,2,3,4]
Explanation:
rotate 1 steps to the right: [7,1,2,3,4,5,6]
rotate 2 steps to the right: [6,7,1,2,3,4,5]
rotate 3 steps to the right: [5,6,7,1,2,3,4]


Example 2:
Input: nums = [-1,-100,3,99], k = 2
Output: [3,99,-1,-100]
Explanation: 
rotate 1 steps to the right: [99,-1,-100,3]
rotate 2 steps to the right: [3,99,-1,-100]

*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
  void rotate(vector<int>& nums, int k) {
    // Version: leetcode上最后一个测试用例超出时间限制：
    // 当前方法的时间复杂度是:O(k*n)
    // for(int i=0;i<k;i++){
    //   int baclele = nums.back();
    //   nums.pop_back();
    //   nums.insert(nums.begin(), baclele);
    // }

    //Version： GPT优化后
    int n = nums.size();
    k = k % n; // 当k大于数组长度时，k取余数
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin() + k);
    reverse(nums.begin() + k, nums.end());
  }
};

//测试用例
TEST(XXXTest, Case1){
  vector<int> input = {1,2,3,4,5,6,7};
  int k=3;
  Solution  solut;
  solut.rotate(input, k);
  vector<int> target = {5,6,7,1,2,3,4};
  EXPECT_EQ(target, input);
}

TEST(XXXTest, Case2){
  vector<int> input = {-1,-100,3,99};
  int k = 2;
  Solution  solut;
  solut.rotate(input, k);
  vector<int> target = {3,99,-1,-100};
  EXPECT_EQ(target, input);
}

int main(int argc, char* argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}