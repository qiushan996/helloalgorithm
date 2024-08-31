/*  题目描述: 190_颠倒二进制数
Reverse bits of a given 32 bits unsigned integer.

Note:
Note that in some languages, such as Java, there is no unsigned integer type. In this case, both input and output will be given as a signed integer type. They should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 2 above, the input represents the signed integer -3 and the output represents the signed integer -1073741825.
 

Example 1:
Input: n = 00000010100101000001111010011100
Output:    964176192 (00111001011110000010100101000000)
Explanation: The input binary string 00000010100101000001111010011100 represents the unsigned integer 43261596, so return 964176192 which its binary representation is 00111001011110000010100101000000.

Example 2:
Input: n = 11111111111111111111111111111101
Output:   3221225471 (10111111111111111111111111111111)
Explanation: The input binary string 11111111111111111111111111111101 represents the unsigned integer 4294967293, so return 3221225471 which its binary representation is 10111111111111111111111111111111.

*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        //位运算：
        //注意是颠倒不是取反运算
        // 1.	初始化结果为 0。
        // 2.	遍历 32 位整数的每一位：
        // •	使用按位与操作 n & 1 获取当前最低位的值。
        // •	将结果左移一位，然后添加最低位的值。
        // •	将输入整数右移一位。
        // 3.	继续这一过程，直到处理完所有 32 位。
        uint32_t  result =0;
        for (int  i = 0; i < 32; i++)
        {
          result = (result <<1) | ( n & 1);
          n >>=1;
        }
        return result;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    uint32_t num = 43261596; //binary:00000010100101000001111010011100
    uint32_t target = 964176192; //00111001011110000010100101000000
    EXPECT_EQ(target, solut.reverseBits(num));
}

TEST(XXXTest, Case2){
    Solution solut;
    uint32_t num = 4294967293; //binary:11111111111111111111111111111101
    uint32_t target = 3221225471; //10111111111111111111111111111111
    EXPECT_EQ(target, solut.reverseBits(num));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
