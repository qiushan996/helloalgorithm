/* 题目: 14_最长公共前缀

Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

Example 1:
Input: strs = ["flower","flow","flight"]
Output: "fl"

Example 2:
Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.

*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      //纵向扫描
      if(strs.empty()) return "";
      for (size_t index = 0; index < strs[0].length(); index++)
      {
        char current = strs[0][index];
        for(int i=1; i<strs.size(); i++){
          if(index >= strs[i].length() || strs[i][index] != current){
            return strs[0].substr(0, index);
          }
        }
      }
      return strs[0];
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<string> strs = {"flower","flow","flight"};
    string target = "fl";
    EXPECT_EQ(target, solut.longestCommonPrefix(strs));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<string> strs = {"dog","racecar","car"};
    string target = "";
    EXPECT_EQ(target, solut.longestCommonPrefix(strs));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
