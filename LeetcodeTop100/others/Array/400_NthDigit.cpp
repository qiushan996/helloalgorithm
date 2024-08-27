/* 题目描述: 400_第N位数字

Given an integer n, return the nth digit of the infinite integer sequence [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ...].
Example 1:
Input: n = 3
Output: 3
Example 2:
Input: n = 11
Output: 0
Explanation: The 11th digit of the sequence 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, ... is a 0, which is part of the number 10.
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        long base = 9, digits = 1;
        while (n - base * digits > 0) {
            n -= base * digits;
            base *= 10;
            digits++;
        }
        
        int index = n % digits;
        if (index == 0) index = digits;
        long num = 1;
        for (int i = 1; i < digits; i++) {
            num *= 10;
        }
        num += (index == digits) ? n / digits - 1 : n / digits;
        
        for (int i = index; i < digits; i++) num /= 10;
        return num % 10;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    EXPECT_EQ(3, solut.findNthDigit(3));
}

TEST(XXXTest, Case2){
    Solution solut;
    EXPECT_EQ(0, solut.findNthDigit(11));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
