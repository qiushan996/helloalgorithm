/* 题目描述: 557_反转字符串中的单词III
Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.

Example 1:
Input: s = "Let's take LeetCode contest"
Output: "s'teL ekat edoCteeL tsetnoc"

Example 2:
Input: s = "Mr Ding"
Output: "rM gniD"

*/
#include<vector>
#include<algorithm>
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
    
    string result;

    for (int  i = 0; i < words.size(); i++)
    {
      reverse(words[i].begin(), words[i].end());
      result += (words[i] + ' ');
    }
    result.resize(result.size() -1);
    return result;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    EXPECT_EQ("s'teL ekat edoCteeL tsetnoc", solut.reverseWords("Let's take LeetCode contest"));
}

TEST(XXXTest, Case2){
    Solution solut;
    EXPECT_EQ("rM gniD", solut.reverseWords("Mr Ding"));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
