/* 347_前K个高频元素

Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

*/
#include<vector>
#include<unordered_map>
#include<queue>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
      //建立元素及其出现频率的哈希表
      std::unordered_map<int, int> frequencyMap;
      for(int num: nums){
        frequencyMap[num]++;
      }

      //最小堆
      auto comp = [&frequencyMap](int n1, int n2){return frequencyMap[n1]>frequencyMap[n2]; };
      std::priority_queue<int, std::vector<int>, decltype(comp)> minheap(comp);

      //维护一个大小为k的最小堆
      for(auto& [num, freq]: frequencyMap){
        minheap.push(num);
        if(minheap.size() > k){
          minheap.pop();
        }
      }

      //收集最小堆中的元素
      std::vector<int> topK;
      while (!minheap.empty())
      {
        topK.push_back(minheap.top());
        minheap.pop();
      }
      
      return topK;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> nums = {1,1,1,2,2,3};
    vector<int> target = {1,2};
    sort(target.begin(), target.end());
    vector<int> result = solut.topKFrequent(nums, 2);
    sort(result.begin(), result.end());
    EXPECT_EQ(target, result);
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> nums = {1};
    vector<int> target = {1};
    sort(target.begin(), target.end());
    vector<int> result = solut.topKFrequent(nums, 1);
    sort(result.begin(), result.end());
    EXPECT_EQ(target, result);
}
int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
