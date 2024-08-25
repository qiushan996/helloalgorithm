/*题目描述: 151_反转字符串中的单词

Given an input string s, reverse the order of the words.

A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

Return a string of the words in reverse order concatenated by a single space.

Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.


Example 1:
Input: s = "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: s = "  hello world  "
Output: "world hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: s = "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
*/
#include<vector>
#include<string>
#include<sstream>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
    //分隔
    std::stringstream iss(s);
    std::vector<string> words;
    string word;
    while (iss>>word)
    {
      words.push_back(word);
    }
    
    //反转
    reverse(words.begin(), words.end());
    string result;
    if(!words.empty()){
      result = words[0];
    }
    for (int  i = 1; i < words.size(); i++)
    {
      result += " " + words[i];
    }
    return result;
     
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    EXPECT_EQ("blue is sky the", solut.reverseWords("the sky is blue"));
}

TEST(XXXTest, Case2){
    Solution solut;
    EXPECT_EQ("world hello", solut.reverseWords("  hello world  "));
}

TEST(XXXTest, Case3){
    Solution solut;
    EXPECT_EQ("example good a", solut.reverseWords("a good   example"));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
