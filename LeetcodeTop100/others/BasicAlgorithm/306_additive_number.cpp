/* 题目描述: 306_累加数
An additive number is a string whose digits can form an additive sequence.

A valid additive sequence should contain at least three numbers.
Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.

Given a string containing only digits, return true if it is an additive number or false otherwise.

Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.

Example 1:
Input: "112358"
Output: true
Explanation: 
The digits can form an additive sequence: 1, 1, 2, 3, 5, 8. 
1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
Example 2:

Input: "199100199"
Output: true
Explanation: 
The additive sequence is: 1, 99, 100, 199. 
1 + 99 = 100, 99 + 100 = 199

*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
      // 1.	遍历可能的数字长度：从最短的数字长度开始，逐步增加长度，寻找可能的前两个数字。
      // 2.	验证累加序列：一旦确定了前两个数字，递归地验证剩下的字符串。
      // 3.	特殊情况处理：需要处理数字可能有前导零的情况，除非数字是 0。
      int n = num.size();
      for(int i =1; i<=n/2; i++){
        for(int j =1; j<=(n-i)/2; j++){
            if(check(num.substr(0, i), num.substr(i, j), num.substr(i+j))){
              return true;
            }
        }
      }
      return false;
    }

private:
    bool check(const string& num1, const string& num2, const string& num3){
      if((num1.size() >1 && num1[0] == '0') || (num2.size()>1 && num2[0] == '0')) return false;
      string sum = add(num1, num2);
      if(sum == num3) return true;
      if(num3.size()<sum.size() || sum!=num3.substr(0, sum.size())) return false;
      return check(num2, sum, num3.substr(sum.size()));

    }
    string add(const string& a, const string& b){
      string res;
      int i = a.size()-1, j = b.size()-1, carry =0;
      while (i >= 0 || j >= 0 || carry) {
          carry += (i >= 0 ? a[i--] - '0' : 0) + (j >= 0 ? b[j--] - '0' : 0);
          res.push_back(carry % 10 + '0');
          carry /= 10;
      }
      reverse(res.begin(), res.end());
      return res;
    }

};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;

    EXPECT_TRUE(solut.isAdditiveNumber("112358"));
}

TEST(XXXTest, Case2){
    Solution solut;

    EXPECT_TRUE(solut.isAdditiveNumber("199100199"));
}
int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
