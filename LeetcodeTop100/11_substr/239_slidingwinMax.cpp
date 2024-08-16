/* 题目解析: 239_滑动窗口最大值

You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the max sliding window.

*/
#include<vector>
#include<deque>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      //可以使用双端队列（deque）的数据结构来解决这个问题，以保持队列的第一个元素始终为当前窗口的最大值。同时，需要确保队列中的元素是当前滑动窗口中的元素的索引，并且这些索引对应的值是单调递减的。
      vector<int> result;
      deque<int> dq;

      for(int i = 0; i< nums.size(); i++){
        if(!dq.empty() && dq.front() == i-k){
          dq.pop_front();
        }

        while (!dq.empty() && nums[i] > nums[dq.back()])
        {
          dq.pop_back();
        }

        //
        dq.push_back(i);
        if(i>=k-1){
          result.push_back(nums[dq.front()]);
        }
        
      }
      return result;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> input = {1,3,-1,-3,5,3,6,7};
    vector<int> target = {3,3,5,5,6,7};

    EXPECT_EQ(target, solut.maxSlidingWindow(input, 3));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> input = { 1};
    vector<int> target = {1};

    EXPECT_EQ(target, solut.maxSlidingWindow(input, 1));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
