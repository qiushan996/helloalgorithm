/*题目描述: 1941_检查是否所有字符出现次数相同

Given a string s, return true if s is a good string, or false otherwise.

A string s is good if all the characters that appear in s have the same number of occurrences (i.e., the same frequency).

Example 1:
Input: s = "abacbc"
Output: true
Explanation: The characters that appear in s are 'a', 'b', and 'c'. All characters occur 2 times in s.

Example 2:
Input: s = "aaabb"
Output: false
Explanation: The characters that appear in s are 'a' and 'b'.
'a' occurs 3 times while 'b' occurs 2 times, which is not the same number of times.
*/

#include<vector>
#include<unordered_map>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool areOccurrencesEqual(string s) {
      //使用hash统计字符出现的次数
      unordered_map<char, int> charmap;
      for(auto ch: s){
        charmap[ch]++;
      }
      
      int freq = charmap.begin()->second;
      for(auto it: charmap){
        if(it.second != freq){
            return false;
        }
      }
      return true;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    EXPECT_TRUE(solut.areOccurrencesEqual("abacbc"));
    EXPECT_FALSE(solut.areOccurrencesEqual("aaabb"));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
