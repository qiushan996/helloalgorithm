/* 题目描述：

Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.

给定一个乱序的整数数组，返回连续元素的最大长度。算法复杂度必须为O(n)


Example 1:

Input: nums = [100,4,200,1,3,2]
Output: 4
Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

Example 2:
Input: nums = [0,3,7,2,5,8,4,6,0,1]
Output: 9

*/
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<iostream>
#include<gtest/gtest.h>

using namespace std;

int longestConsecutive(vector<int>& nums) {

  //创建一个hash 表存放数组数据
  unordered_set<int> num_set(nums.begin(), nums.end());  //无序

  int longest_seq = 0;

  for(int num : nums){
    if(num_set.find(num-1) == num_set.end()){
        int current_num = num;
        int current_seq = 1;

        while (num_set.find(current_num+1) !=num_set.end())
        {
          current_num++;
          current_seq++;
        }

        longest_seq = max(longest_seq, current_seq);
        
    }
  }
  return longest_seq;
}


TEST(longest_sequenceTest, case1){
  vector<int> input1 = {100,4,200,1,3,2};
  int target =4;
  int result = longestConsecutive(input1);
  EXPECT_EQ(target, result);
}

TEST(longest_sequenceTest, case2){
  vector<int> input1 = {0,3,7,2,5,8,4,6,0,1};
  int target =9;
  int result = longestConsecutive(input1);
  EXPECT_EQ(target, result);
}

int main(int argc, char* argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}