/*题目描述: 819_最常见的单词
Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.
The words in paragraph are case-insensitive and the answer should be returned in lowercase.

Example 1:

Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
Output: "ball"
Explanation: 
"hit" occurs 3 times, but it is a banned word.
"ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
Note that words in the paragraph are not case sensitive,
that punctuation is ignored (even if adjacent to words, such as "ball,"), 
and that "hit" isn't the answer even though it occurs more because it is banned.
Example 2:

Input: paragraph = "a.", banned = []
Output: "a"
*/
#include<vector>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<sstream>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
    // 1.	标准化文本：将段落转换为统一小写，并使用正则表达式或其他方法去除标点符号。
    // 2.	分词：将处理后的文本分割成单词。
    // 3.	计数和过滤：使用哈希表记录每个单词的出现次数，同时忽略禁用单词。
    // 4.	查找最大值：遍历哈希表，找出出现次数最多的单词。
    set<string> banset(banned.begin(), banned.end());
    map<string, int> count;
    //将非字符/标点符号转化为人空格
    for(auto &c: paragraph) c = isalpha(c)? tolower(c):' ';

    istringstream ss(paragraph);
    string word;
    pair<string, int> res("", 0);
    while (ss>>word)
    {
      if(banset.find(word) == banset.end()){
        count[word]++;
        if(count[word]>res.second){
          res = make_pair(word, count[word]);
        }
      }
    }
    return res.first;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    string  input = "Bob hit a ball, the hit BALL flew far after it was hit.";
    vector<string> word = {"hit"};
    EXPECT_EQ("ball", solut.mostCommonWord(input, word));
}

TEST(XXXTest, Case2){
    Solution solut;
    string  input = "a.";
    vector<string> word = {};
    EXPECT_EQ("a", solut.mostCommonWord(input, word));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
