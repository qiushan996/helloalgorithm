/*题目描述: 506_相对名次

You are given an integer array score of size n, where score[i] is the score of the ith athlete in a competition. All the scores are guaranteed to be unique.
您将获得一个大小为 n 的整数数组 score，其中 score[i] 是比赛中第 i 位运动员的得分。所有得分都保证是唯一的。

The athletes are placed based on their scores, where the 1st place athlete has the highest score, the 2nd place athlete has the 2nd highest score, and so on. The placement of each athlete determines their rank:
运动员的排名依据得分，其中第一名运动员得分最高，第二名运动员得分第二高，依此类推。每位运动员的排名决定了他们的排名：

The 1st place athlete's rank is "Gold Medal".
The 2nd place athlete's rank is "Silver Medal".
The 3rd place athlete's rank is "Bronze Medal".
For the 4th place to the nth place athlete, their rank is their placement number (i.e., the xth place athlete's rank is "x").
Return an array answer of size n where answer[i] is the rank of the ith athlete.

Example 1:
Input: score = [5,4,3,2,1]
Output: ["Gold Medal","Silver Medal","Bronze Medal","4","5"]
Explanation: The placements are [1st, 2nd, 3rd, 4th, 5th].

Example 2:
Input: score = [10,3,8,9,4]
Output: ["Gold Medal","5","Bronze Medal","Silver Medal","4"]
Explanation: The placements are [1st, 5th, 3rd, 2nd, 4th].

*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
      //方法1: 用map标记
      // vector<int> t = score;
      // map<int, int> m;
      // vector<std::string> res;
      // sort(score.begin(), score.end(), greater<int>());
      // for(int i=0;i<score.size(); i++){
      //   m[score[i]] = i;
      // }

      // for(int i=0; i<t.size(); i++){
      //   if(m[t[i]] == 0) res.push_back("Gold Medal");
      //   else if(m[t[i]] == 1) res.push_back("Silver Medal");
      //   else if(m[t[i]] == 2) res.push_back("Bronze Medal");
      //   else res.push_back(to_string(m[t[i]]+1));
      // }
      // return res;

      //方法2:
      int  n = score.size();
      std::vector<std::pair<int, int>> indexScore(n);
      for(int i=0; i<n;i++){
        indexScore[i] = {score[i], i};
      }

      //排序
      sort(indexScore.rbegin(), indexScore.rend());

      std::vector<std::string> ans(n);

      for(int i=0; i<n; i++){
        if(i==0) ans[indexScore[i].second] = "Gold Medal";
        else if(i ==1 ) ans[indexScore[i].second] = "Silver Medal";
        else if(i ==2) ans[indexScore[i].second] = "Bronze Medal";
        else ans[indexScore[i].second] = std::to_string(i + 1);
      }
      return ans;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> input = {5,4,3,2,1};
    vector<std::string> target = {"Gold Medal","Silver Medal","Bronze Medal","4","5"};
    EXPECT_EQ(target, solut.findRelativeRanks(input));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> input = {10,3,8,9,4};
    vector<std::string> target = {"Gold Medal","5","Bronze Medal","Silver Medal","4"};
    EXPECT_EQ(target, solut.findRelativeRanks(input));
}


int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
