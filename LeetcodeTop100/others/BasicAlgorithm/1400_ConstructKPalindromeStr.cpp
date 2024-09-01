/*题目描述: 1400_构造k个回文字符串
Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.

Example 1:
Input: s = "annabelle", k = 2
Output: true
Explanation: You can construct two palindromes using all characters in s.
Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
Example 2:
Input: s = "leetcode", k = 3
Output: false
Explanation: It is impossible to construct 3 palindromes using all the characters of s.
Example 3:
Input: s = "true", k = 4
Output: true
Explanation: The only possible solution is to put each character in a separate string.
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    // bool canConstruct(string s, int k) {
    //   if(s.length()<=k) return false;

    //   for (int  i = 1; i < s.length(); i++)
    //   {
    //     string s1 = s.substr(0, i);
    //     string s2 = s.substr(i, s.length()-1);
    //     std::cout<<"s1: "<<s1<<" s2:"<<s2<<std::endl;
    //     if(isPalindrome(s1) && isPalindrome(s2)) return true;
    //   }
    //   return false;
    // }

    // bool isPalindrome(string str){
    //     for(int i=0, j = str.length(); i<=j; ){
    //       if(str[i]!= str[j]) return false;
    //       i++;
    //       j--;
    //     }
    //     return true;
    // }

    //1.	计算每个字符的出现次数：使用哈希表（或数组）来统计每个字符出现的次数。
    // 2.	计算奇数次数字符的数量：遍历字符频次，计算有多少个字符出现了奇数次。
    // 3.	比较奇数次数与 k 的关系：如果奇数次数大于 k，则不可能构造出 k 个回文字符串；如果 s 的长度小于 k，也不可能构造出 k 个字符串。
    // 4.	返回结果：如果以上条件都满足，返回 true，否则返回 false。
    bool canConstruct(string s, int k) {
        if (s.length() < k) return false;

        std::unordered_map<char, int> count;
        for (char c : s) {
            count[c]++;
        }

        int odd = 0;
        for (auto& p : count) {
            if (p.second % 2 == 1) {
                odd++;
            }
        }

        return odd <= k;
    }

};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    EXPECT_TRUE(solut.canConstruct("annabelle", 2));
}

TEST(XXXTest, Case2){
    Solution solut;
    EXPECT_FALSE(solut.canConstruct("leetcode", 3));
}


int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
