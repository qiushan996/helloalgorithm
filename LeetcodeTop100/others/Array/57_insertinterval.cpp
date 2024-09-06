/*题目描述: 57_插入区间

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Note that you don't need to modify intervals in-place. You can make a new array and return it.

Example 1:
Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
Output: [[1,5],[6,9]]

Example 2:
Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      //遍历区间列表，根据新区间的位置和其他区间的关系进行适当的操作：
      // 1.	添加非重叠区间：如果当前区间的结束位置小于新区间的开始位置，说明没有重叠，将当前区间添加到结果列表。
      // 2.	合并重叠区间：如果当前区间与新区间有重叠（即当前区间的开始位置小于等于新区间的结束位置，并且当前区间的结束位置大于等于新区间的开始位置），则将它们合并。合并后的新区间不立即添加到结果列表，而是继续与后续的区间进行比较和合并。
      // 3.	添加剩余非重叠区间：如果当前区间的开始位置大于新区间的结束位置，说明新区间已经处理完成，可以将其添加到结果列表（如果还未添加），并继续添加剩余的区间。

      std::vector<std::vector<int>> result;
      int i = 0, n = intervals.size();
      while (i < n && intervals[i][1] < newInterval[0]) {
          result.push_back(intervals[i]);
          i++;
      }

      while (i < n && intervals[i][0] <= newInterval[1]) {
          newInterval[0] = std::min(newInterval[0], intervals[i][0]);
          newInterval[1] = std::max(newInterval[1], intervals[i][1]);
          i++;
      }
      result.push_back(newInterval);

      while (i < n) {
          result.push_back(intervals[i]);
          i++;
      }
      return result;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<vector<int>> input = {{1,3}, {6,9}};
    vector<vector<int>> target = {{1,5},{6,9}};
    vector<int> nums = {2,5};
    EXPECT_EQ(target, solut.insert(input, nums));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<vector<int>> input = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<vector<int>> target = {{1,2},{3,10},{12,16}};
    vector<int> nums = {4,8};
    EXPECT_EQ(target, solut.insert(input, nums));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
