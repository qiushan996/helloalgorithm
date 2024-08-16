/*  题目解析: 76_最小的覆盖子串

Given two strings s and t of lengths m and n respectively, return the minimum window  substring of s such that every character in t (including duplicates) is included in the window. If there is no such substring, return the empty string "".
给定两个字符串 s 和 t，长度分别为 m 和 n，返回 s 的最小窗口子字符串，使得 t 中的每个字符（包括重复字符）都包含在窗口中。如果没有这样的子字符串，则返回空字符串 ""。

The testcases will be generated such that the answer is unique.

Example 1:
Input: s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
Explanation: The minimum window substring "BANC" includes 'A', 'B', and 'C' from string t.

Example 2:
Input: s = "a", t = "a"
Output: "a"
Explanation: The entire string s is the minimum window.

Example 3:
Input: s = "a", t = "aa"
Output: ""
Explanation: Both 'a's from t must be included in the window.
Since the largest window of s only has one 'a', return empty string.
*/
#include<unordered_map>
#include<string>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
      //使用滑动窗口方法来解决
      unordered_map<char, int> need, window;
      for(char c: t) need[c]++;

      int left =0, right =0;
      int valid = 0;

      int start = 0, len = numeric_limits<int>::max();
      while (right < s.size())
      {
        char c = s[right];
        right++;

        if(need.count(c)){
          window[c]++;
          if(window[c]==need[c]) valid++;
        }
        while (valid == need.size())
        {
          if(right - left < len){
            start = left;
            len = right - left;
          }

          char d = s[left];
          left++;
          if(need.count(d)){
            if(window[d]==need[d])
              valid--;
            window[d]--;
          }
        }
        
      }
      return len == numeric_limits<int>::max() ? "": s.substr(start, len);

    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    string input = "ADOBECODEBANC";
    string  result = solut.minWindow(input, "ABC");
    EXPECT_EQ("BANC", result);
}

TEST(XXXTest, Case2){
    Solution solut;
    string input = "a";
    string  result = solut.minWindow(input, "a");
    EXPECT_EQ("a", result);
}

TEST(XXXTest, Case3){
    Solution solut;
    string input = "a";
    string  result = solut.minWindow(input, "aa");
    EXPECT_EQ("", result);
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
