/* 题目描述: 22_括号生成器
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
给定 n 对括号，编写一个函数来生成格式正确的括号的所有组合。

Example 1:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]


Example 2:
Input: n = 1
Output: ["()"]



*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
      vector<string>  result ;
      string current;
      backtrack(result,current,0, 0, n);
      return result;
    }
private:
    //终止条件生成的组合长度为2*n时添加到结果中
    void backtrack(vector<string>& result, string&  current, int open, int close, int max){
      if(current.size() == max*2){
        result.push_back(current);
        return ;
      }

      if(open < max){
        current.push_back('(');
        backtrack(result, current, open+1,close, max);
        current.pop_back();
      }
      if(close<open){
        current.push_back(')');
        backtrack(result,current, open, close+1, max);
        current.pop_back();
      }
    }
};

//测试用例
TEST(XXXTest, Case1){
  vector<string> target = {"((()))","(()())","(())()","()(())","()()()"};
  Solution solut;
  vector<string> result = solut.generateParenthesis(3);
  EXPECT_EQ( target, result);
}

TEST(XXXTest, case2){
  vector<string> target = {"()"};
  Solution solut;
  vector<string> result = solut.generateParenthesis(1);
  EXPECT_EQ( target, result);
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
