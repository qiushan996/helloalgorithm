/*题目描述: 1450_在既定时间做作业的学生人数
算法基础：枚举
Given two integer arrays startTime and endTime and given an integer queryTime.
The ith student started doing their homework at the time startTime[i] and finished it at time endTime[i].

Return the number of students doing their homework at time queryTime. More formally, return the number of students where queryTime lays in the interval [startTime[i], endTime[i]] inclusive.

Example 1:
Input: startTime = [1,2,3], endTime = [3,2,7], queryTime = 4
Output: 1
Explanation: We have 3 students where:
The first student started doing homework at time 1 and finished at time 3 and wasn't doing anything at time 4.
The second student started doing homework at time 2 and finished at time 2 and also wasn't doing anything at time 4.
The third student started doing homework at time 3 and finished at time 7 and was the only student doing homework at time 4.

Example 2:
Input: startTime = [4], endTime = [4], queryTime = 4
Output: 1
Explanation: The only student was doing their homework at the queryTime.
*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        int ans = 0;
        for (size_t i = 0; i < startTime.size(); i++)
        {
          if(endTime[i]>=queryTime && startTime[i]<=queryTime ) ans++;
        }
      return ans;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> start = {1,2,3};
    vector<int> end = {3,2,7};
    EXPECT_EQ(1, solut.busyStudent(start, end, 4));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> start = {4};
    vector<int> end = {4};
    EXPECT_EQ(1, solut.busyStudent(start, end, 4));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
