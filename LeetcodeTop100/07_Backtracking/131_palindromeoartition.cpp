/*题目描述：131_分隔回文串

Given a string s, partition s such that every  substring of the partition is a 
palindrome. Return all possible palindrome partitioning of s.
给定一个字符串 s，对 s 进行分区，使得分区中的每个子字符串都是回文。返回 s 的所有可能的回文分区。

Example 1:
Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]

Example 2:
Input: s = "a"
Output: [["a"]]
*/
#include<vector>
#include<string>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) {
      vector<vector<string>> result;
      vector<string> current;
      backtrack(s, 0, current, result);
      return result;
    }
private:

    void backtrack(const string& s, int start, vector<string> current, vector<vector<string>>& result){
      if(start == s.length()){
        result.push_back(current);
        return ;
      }

      for(int end = start; end < s.length(); end++){
        if(isPalindrome(s, start, end)){
          current.push_back(s.substr(start, end-start+1));
          backtrack(s, end+1, current, result);
          current.pop_back();
        }
      }
    }
    //判断一个字符串在指定位置是否是回文字符串
    bool isPalindrome(const string& s, int start, int end){
      while (start<end)
      {
        if(s[start++] != s[end--]){
          return false;
        }
      }
      return true;  
    }
};

//测试用例
TEST(XXXTest, Case1){
  string input = "aab";
  Solution solut;
  vector<vector<string>> target = {{"a","a","b"}, {"aa","b"}};
  vector<vector<string>> result = solut.partition(input);
  EXPECT_EQ(target, result );
}
TEST(XXXTest, Case2){
  string input = "a";
  Solution solut;
  vector<vector<string>> target = {{"a"}};
  vector<vector<string>> result = solut.partition(input);
  EXPECT_EQ(target, result );
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
