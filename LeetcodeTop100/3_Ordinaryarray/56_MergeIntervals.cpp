/* 题目描述: 56_合并子区间_merge-intervals


Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

给定一个间隔数组，其中 intervals[i] = [starti, endi]，合并所有重叠间隔，并返回覆盖输入中所有间隔的非重叠间隔数组。

Example 1:
Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:
Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;


class Solution {
public:
  bool static compareinterval(vector<int> res1, vector<int> res2){
    return res1[0]<res2[0];
  }
  
  
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> merged;

    //排序
    sort(intervals.begin(), intervals.end(), compareinterval);

    merged.push_back(intervals[0]);

    for(int i=1; i<intervals.size(); i++){
      //两个区间没有交集
      if(merged.back()[1] >=intervals[i][0]){
        merged.back()[1] = max(merged.back()[1], intervals[i][1]);
      }else{
        merged.push_back(intervals[i]);
      }
    }
    return merged;
  }


};

// bool CompareVectors(vector<vector<int> res1, vector<vector<int>> res2){

// }

TEST(MergeintervalsTest, case1){
  vector<vector<int>> input = {{1,3},{2,6},{8,10},{15,18}};

  vector<vector<int>> target = {{1,6},{8, 10},{15,18}};
  Solution solut;
  vector<vector<int>> result = solut.merge(input);
  EXPECT_TRUE(target==result);
}

TEST(MergeintervalsTest, case2){
  vector<vector<int>> input = {{1,4},{4, 5}};

  vector<vector<int>> target = {{1,5}};
  Solution solut;
  vector<vector<int>> result = solut.merge(input);
  EXPECT_TRUE(target==result);
}

TEST(MergeintervalsTest, case3){
  vector<vector<int>> input = {{1,4},{0,4}};

  vector<vector<int>> target = {{0, 4}};
  Solution solut;
  vector<vector<int>> result = solut.merge(input);
  EXPECT_TRUE(target==result);
}


int main(int argc, char* argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
