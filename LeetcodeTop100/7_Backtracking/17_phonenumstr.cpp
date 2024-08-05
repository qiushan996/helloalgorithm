/* 题目描述: 
Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.

Example 1:
Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

Example 2:
Input: digits = ""
Output: []

Example 3:
Input: digits = "2"
Output: ["a","b","c"]

*/
#include<string>
#include<unordered_map>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
      if(digits.empty()) return {};

      vector<string> result;
      string current;
      std::unordered_map<char,string > phone = {
           {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
           {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
      };
      backtrack(digits, 0, phone,current,result);
      return result;
    }
private:
   void backtrack(const string& digits, int index, const unordered_map<char, string>& phone,
          string& current, vector<string>& result){
        if(index == digits.length()){
          result.push_back(current);
          return;
        }
        for(char c : phone.at(digits[index])){
          current.push_back(c);
          backtrack(digits,index+1,phone, current, result);
          current.pop_back();
        }
   }
};

//测试用例
TEST(XXXTest, Case1){
  string input = "23";
  vector<string> target = {"ad","ae","af","bd","be","bf","cd","ce","cf"};
  Solution solut;
  vector<string> result = solut.letterCombinations(input);
  EXPECT_EQ( target, result);
}
TEST(XXXTest, Case2){
  string input = "";
  vector<string> target = {};
  Solution solut;
  vector<string> result = solut.letterCombinations(input);
  EXPECT_EQ( target, result);
}
TEST(XXXTest, Case3){
  string input = "2";
  vector<string> target = {"a", "b","c"};
  Solution solut;
  vector<string> result = solut.letterCombinations(input);
  EXPECT_EQ( target, result);
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
