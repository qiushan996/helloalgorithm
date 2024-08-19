/*题目描述: 215_数组中的第k个最大元素

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 
Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5

Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

*/
#include<vector>
#include<queue>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
      //有几种方法可以解决这个问题，包括排序数组和使用最小堆（或优先队列）等。最直接的方法是排序数组，但更高效的方法是使用最小堆或快速选择算法
      std::priority_queue<int, std::vector<int>, std::greater<int>> minheap;
      for(int num: nums){
        if(minheap.size() < k){
          minheap.push(num);
        }else if(num > minheap.top()){
          minheap.pop();
          minheap.push(num);
        }
      }
      return minheap.top();
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> nums = {3,2,1,5,6,4};

    EXPECT_EQ(5, solut.findKthLargest(nums, 2));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> nums = {3,2,3,1,2,4,5,5,6};
    EXPECT_EQ(4, solut.findKthLargest(nums, 4));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
