/*题目解析：438 找到字符串中所有的字母异位词

Given two strings s and p, return an array of all the start indices of p's anagrams in s. You may return the answer in any order.
An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.
给定两个字符串 s 和 p，返回 s 中 p 的字谜的所有起始索引的数组。您可以按任何顺序返回答案。
字谜是通过重新排列不同单词或短语的字母形成的单词或短语，通常使用所有原始字母一次。

相比于No.3 一题，本题目中没有了子串顺序的限制。

Example 1:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
      vector<int> result;
      if(s.length() < p.length()) return result;
      
      vector<int> freq(26,0);
      vector<int> windows_freq(26, 0);

      for(char c: p){
        freq[c - 'a']++;
      }

      for(int i=0; i < p.length(); i++){
        windows_freq[s[i]-'a']++;
      }

      if(freq == windows_freq) result.push_back(0);

      //slide window
      for(int i = p.length(); i < s.length(); i++){
        windows_freq[s[i - p.length()] - 'a']--;
        windows_freq[s[i] - 'a']++;
        if(freq == windows_freq) {
          result.push_back(i - p.length() +1);
        }
      }
      return result;

    }
};

//测试用例
TEST(XXXTest, Case1){
  Solution solut;
  vector<int> result = solut.findAnagrams("cbaebabacd", "abc");
  vector<int> target = {0, 6};
  EXPECT_EQ( target, result);
}

TEST(XXXTest, Case2){
  Solution solut;
  vector<int> result = solut.findAnagrams("abab", "ab");
  vector<int> target = {0,1,2};
  EXPECT_EQ( target, result);
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
