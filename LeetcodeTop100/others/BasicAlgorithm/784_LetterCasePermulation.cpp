/*题目描述: 784_字母大小写全排列
Given a string s, you can transform every letter individually to be lowercase or uppercase to create another string.

Return a list of all possible strings we could create. Return the output in any order.

Example 1:

Input: s = "a1b2"
Output: ["a1b2","a1B2","A1b2","A1B2"]
Example 2:

Input: s = "3z4"
Output: ["3z4","3Z4"]


*/
#include<vector>
#include<string>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<string> letterCasePermutation(string s) {
      vector<string> result;
      //参数:结果字符串、开始位置、字符串长度、字符串
      backtrack(s, 0, "", result);
      return result;

    }
    // void backtrack(vector<string>& result, int index, string current, string& S){
    //   if(index == S.length() ){
    //     result.push_back(current);
    //     return ;
    //   }
    //   if(isdigit(S[index])){
    //     backtrack(result, index+1, current + S[index], S);
    //   }else{
    //     backtrack(result, index+1, current + std::tolower(S[index]), S);
    //     backtrack(result, index+1, current + std::toupper(S[index]), S);
    //   }
    // }

    void backtrack(const std::string &S, int index, std::string current, std::vector<std::string> &result) {
    if (index == S.size()) {
        result.push_back(current);
        return;
    }

    if (std::isdigit(S[index])) {
        backtrack(S, index + 1, current + S[index], result);
    } else {
        backtrack(S, index + 1, current + static_cast<char>(std::tolower(S[index])), result);
        backtrack(S, index + 1, current + static_cast<char>(toupper(S[index])), result);
    }
}
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<string> target = {"a1b2","a1B2","A1b2","A1B2"};
    EXPECT_EQ(target, solut.letterCasePermutation("a1b2"));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<string> target = {"3z4","3Z4"};
    EXPECT_EQ(target, solut.letterCasePermutation("3z4"));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
