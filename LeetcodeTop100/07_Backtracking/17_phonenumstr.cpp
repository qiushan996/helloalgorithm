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
      //处理特殊情况: 给的字符串是一个空串
      if(digits.empty()) return {};

      vector<string> result;  //定义返回结果
      string current;         //构建当前组合

      //使用map构建数字-字母的映射表
      std::unordered_map<char,string > phone = {
           {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
           {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
      };
   
      //定义回溯函数
      //从第一个数字开始，递归的生成每个位置可能的字母组合
      backtrack(digits, 0, phone,current,result);
      return result;
    }
private:
   /*
   回溯函数：
   digits: 输入的数字字符串
   index: 当前处理的数字在digist中的位置
   phone: 数字到字母的映射
   current: 当前正在构建的字母组合
   result: 存储所有有效组合的结果
   */
   void backtrack(const string& digits, int index, const unordered_map<char, string>& phone,
          string& current, vector<string>& result){

        //终止条件：当生成的组合长度等于输入数字的长度时，组合完成，添加到结果列表中
        if(index == digits.length()){
          result.push_back(current);
          return;
        }
        //递归过程：遍历当前数字对应的字母串中的每个字母，递归地生成组合。
        //先去输入字符串中的每一个数字字符；
        //根据数字字符获在字典中获取数字对应的字符串，如2:abc
        //遍历abc
        for(char c : phone.at(digits[index])){
          //abc中的每一个字母添加到current中
          current.push_back(c);
          //递归调用backtrack函数，处理下一个数字index + 1
          backtrack(digits,index + 1,phone, current, result);
          //从current中移除，尝试下一个字母
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
