/* 题目描述: 435_无重叠区间
Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Example 1:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.

Example 2:
Input: intervals = [[1,2],[1,2],[1,2]]
Output: 2
Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.

Example 3:
Input: intervals = [[1,2],[2,3]]
Output: 0
Explanation: You don't need to remove any of the intervals since they're already non-overlapping.

*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
      //使用贪心算法来解决这个问题，关键是按照区间的结束时间进行排序，然后贪心地选择结束最早的区间，这样可以留给后面更多的空间来放置其他区间。
      if(intervals.empty()) return 0;

      //排序
      sort(intervals.begin(), intervals.end(), [](const vector<int> &a, const vector<int>&b){
        return a[1]<b[1];
      });

      int count=0, end = intervals[0][1];
      for(int i=1; i<intervals.size(); i++){
        if(intervals[i][0]>=end){
          //没有重叠
          end = intervals[i][1];
        }else{
          ++count;
        }
      }
      return count++;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<vector<int>> intervals = {{1,2}, {2,3}, {3, 4}, {1,3}};
    EXPECT_EQ(1, solut.eraseOverlapIntervals(intervals));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<vector<int>> intervals = {{1,2}, {1,2}, {1,2}};
    EXPECT_EQ(2, solut.eraseOverlapIntervals(intervals));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
