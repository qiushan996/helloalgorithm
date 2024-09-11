/* 题目描述: 91_解码方法
You have intercepted a secret message encoded as a string of numbers. The message is decoded via the following mapping:

"1" -> 'A'

"2" -> 'B'

...

"25" -> 'Y'

"26" -> 'Z'

However, while decoding the message, you realize that there are many different ways you can decode the message because some codes are contained in other codes ("2" and "5" vs "25").

For example, "11106" can be decoded into:

"AAJF" with the grouping (1, 1, 10, 6)
"KJF" with the grouping (11, 10, 6)
The grouping (1, 11, 06) is invalid because "06" is not a valid code (only "6" is valid).
Note: there may be strings that are impossible to decode.

Given a string s containing only digits, return the number of ways to decode it. If the entire string cannot be decoded in any valid way, return 0.
Example 1:

Input: s = "12"

Output: 2

Explanation:

"12" could be decoded as "AB" (1 2) or "L" (12).

Example 2:

Input: s = "226"

Output: 3

Explanation:

"226" could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).

Example 3:

Input: s = "06"

Output: 0

Explanation:

"06" cannot be mapped to "F" because of the leading zero ("6" is different from "06"). In this case, the string is not a valid encoding, so return 0.
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
    //这是一个典型的动态规划问题。基本思路是使用一个数组 dp，其中 dp[i] 表示以第 i 个字符结尾的子字符串的解码方法数。然后通过迭代计算 dp[i]。

    // 动态规划步骤

    // 	1.	初始化：dp[0] = 1，因为空字符串有 1 种解码方式。
    // 	2.	状态转移方程：
    // 	•	对于每个字符 s[i]，如果 s[i] != '0'，说明它可以作为一个独立的字符解码，因此 dp[i] += dp[i - 1]。
    // 	•	如果 s[i-1:i] 的值在 10 到 26 之间，说明可以将这两个字符组合起来解码，因此 dp[i] += dp[i - 2]。
    // 	3.	边界条件：如果字符为 '0'，则不能单独解码。

    //边界条件
      if(s.empty() || s[0] == '0') return 0;
      int n = s.size();
      vector<int> dp(n+1, 0);
      dp[0]  =1;
      dp[1] = (s[0]!= '0')? 1:0;
      for (int i = 2; i <= n; ++i) {
        int oneDigit = s[i - 1] - '0';  // 当前字符
        int twoDigits = std::stoi(s.substr(i - 2, 2));  // 前两个字符组合

        if (oneDigit >= 1 && oneDigit <= 9) {
            dp[i] += dp[i - 1];  // 当前字符可单独解码
        }
        if (twoDigits >= 10 && twoDigits <= 26) {
            dp[i] += dp[i - 2];  // 前两个字符可组合解码
        }
      }
        return dp[n];
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    EXPECT_EQ(2, solut.numDecodings("12"));
    EXPECT_EQ(3, solut.numDecodings("226"));
    EXPECT_EQ(0, solut.numDecodings("06"));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
