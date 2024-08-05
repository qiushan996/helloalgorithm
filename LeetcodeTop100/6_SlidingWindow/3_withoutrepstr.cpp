/* 题目解析: 3_无重复字符的最长字串

Given a string s, find the length of the longest substring without repeating characters.
给一个string类型的字符串，找到没有重复字符的最长字串(子串要连续，不能间断)

Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include<algorithm>
#include<string>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int len = s.size();
        // int sq[128] = {0};
        // int mx = 0;
        // for(int l=0, r=0; r<len; r++){
        //   l = max(sq[s[r]], l);
        //   mx = max(mx, r-l+1);
        //   sq[s[r]] = r+1;

        // }
        // return mx;

        unordered_map<char, int> char_index;
        int max_length = 0;
        int start = 0;
        
        for (int end = 0; end < s.length(); end++) {
            if (char_index.find(s[end]) != char_index.end() && char_index[s[end]] >= start) {
                start = char_index[s[end]] + 1;
            } else {
                max_length = max(max_length, end - start + 1);
            }
            //更新子串结尾的字符
            char_index[s[end]] = end;
        }
        
        return max_length;
    }
};

//测试用例
TEST(XXXTest, Case1){
  string  input = "abcabcbb";
  Solution  solut;
  EXPECT_EQ(3, solut.lengthOfLongestSubstring(input) );
}

TEST(XXXTest, Case2){
  string  input = "bbbbb";
  Solution  solut;
  EXPECT_EQ(1, solut.lengthOfLongestSubstring(input) );
}

TEST(XXXTest, Case3){
  string  input = "pwwkew";
  Solution  solut;
  EXPECT_EQ(3, solut.lengthOfLongestSubstring(input) );
}


int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
