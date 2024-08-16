/* 题目描述: 739_每日温度

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
给定一个整数数组，温度代表每日温度，返回一个数组答案，其中 answer[i] 是第 i 天之后需要等待多少天才能获得更高的温度。如果未来没有哪一天可以实现这一点，则保留 answer[i] == 0。

Example 1:
Input: temperatures = [73,74,75,71,69,72,76,73]
Output: [1,1,4,2,1,1,0,0]

Example 2:
Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]

Example 3:
Input: temperatures = [30,60,90]
Output: [1,1,0]
*/

#include<vector>
#include<stack>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
      //  使用暴力破解，时间复杂度O(n^2), 最后一个测试用例超时
      // vector<int> result;
      // for(int i=0; i < temperatures.size(); i++){
      //   int current = temperatures[i];
      //   int days = 0;
      //   //找最近的大于current的一天，如果没找到，则为0
      //   for(int j = i+1; j<temperatures.size(); j++){
      //     if(temperatures[j] > current){
      //       days = j - i;
      //       break;
      //     }
      //   }   
      //   result.push_back(days);     
      // }
      // return result;

      //使用单调栈来减少时间复杂度的方法
      int n = temperatures.size();
      vector<int> result(n, 0);
      stack<int> tempStack;  // 存储温度索引

      for(int i=0; i < n; i++){
        while (!tempStack.empty() && temperatures[i]>temperatures[tempStack.top()])
        {
          int idx = tempStack.top();
          tempStack.pop();
          result[idx] = i -idx;
        }
        tempStack.push(i);
      }
      return result;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> input = {73,74,75,71,69,72,76,73};
    vector<int> target = {1,1,4,2,1,1,0,0};
    EXPECT_EQ(target, solut.dailyTemperatures(input));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> input = {30,40,50,60};
    vector<int> target = {1,1,1,0};
    EXPECT_EQ(target, solut.dailyTemperatures(input));
}

TEST(XXXTest, Case3){
    Solution solut;
    vector<int> input = {30,60,90};
    vector<int> target = {1,1,0};
    EXPECT_EQ(target, solut.dailyTemperatures(input));
}


TEST(XXXTest, Case4){
    Solution solut;
    vector<int> input = {89,62,70,58,47,47,46,76,100,70};
    vector<int> target = {8,1,5,4,3,2,1,1,0,0};
    EXPECT_EQ(target, solut.dailyTemperatures(input));
}



int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
