/*题目描述: 452_用最少量的箭引爆气球
There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.

Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.

Given the array points, return the minimum number of arrows that must be shot to burst all balloons.

Example 1:

Input: points = [[10,16],[2,8],[1,6],[7,12]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 6, bursting the balloons [2,8] and [1,6].
- Shoot an arrow at x = 11, bursting the balloons [10,16] and [7,12].
Example 2:

Input: points = [[1,2],[3,4],[5,6],[7,8]]
Output: 4
Explanation: One arrow needs to be shot for each balloon for a total of 4 arrows.
Example 3:

Input: points = [[1,2],[2,3],[3,4],[4,5]]
Output: 2
Explanation: The balloons can be burst by 2 arrows:
- Shoot an arrow at x = 2, bursting the balloons [1,2] and [2,3].
- Shoot an arrow at x = 4, bursting the balloons [3,4] and [4,5].
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
      //	1.	排序：首先按照每个气球的结束坐标进行排序。
      //  2.	贪心选择：遍历排序后的气球，每次选择射箭的位置为当前未被覆盖的气球的结束坐标。这保证了我们可以用最少的箭引爆尽可能多的气球。
      //  3.	更新射箭次数：每次射出一箭，更新计数器，并检查哪些气球被这一箭引爆，继续射下一箭直到所有气球都被覆盖。
              if (points.empty()) return 0;
        
      // Sort the balloons by their end coordinates
      std::sort(points.begin(), points.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
          return a[1] < b[1];
      });
      
      int arrows = 1;
      int end = points[0][1];
      for (const auto& point : points) {
          if (point[0] > end) {
              arrows++;
              end = point[1];
          }
      }
      
      return arrows;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<vector<int>> input = {{10,16},{2,8},{1,6},{7,12}};
    EXPECT_EQ(2, solut.findMinArrowShots(input));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<vector<int>> input = {{1,2},{3,4},{5,6},{7,8}};
    EXPECT_EQ(4, solut.findMinArrowShots(input));
}

TEST(XXXTest, Case3){
    Solution solut;
    vector<vector<int>> input = {{1,2},{2,3},{3,4},{4,5}};
    EXPECT_EQ(2, solut.findMinArrowShots(input));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
