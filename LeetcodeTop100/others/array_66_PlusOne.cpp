/*题目描述: 66_加一
You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.

Increment the large integer by one and return the resulting array of digits.

Example 1:
Input: digits = [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].

Example 2:
Input: digits = [4,3,2,1]
Output: [4,3,2,2]
Explanation: The array represents the integer 4321.
Incrementing by one gives 4321 + 1 = 4322.
Thus, the result should be [4,3,2,2].

Example 3:
Input: digits = [9]
Output: [1,0]
Explanation: The array represents the integer 9.
Incrementing by one gives 9 + 1 = 10.
Thus, the result should be [1,0].

*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
      int n = digits.size();
      //从最后一位开始加
      for(int i = n-1; i>=0; i--){
        if(digits[i]<9){
          digits[i]++;
          return digits;
        }
        digits[i] = 0;
      }

      std:vector<int> newDigits(n+1);
      newDigits[0] = 1;
      return newDigits;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> input = {1,2,3};
    vector<int> target = {1,2,4};
    EXPECT_EQ(target, solut.plusOne(input));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> input = {4,3,2,1};
    vector<int> target = {4,3,2,2};
    EXPECT_EQ(target, solut.plusOne(input));
}

TEST(XXXTest, Case3){
    Solution solut;
    vector<int> input = {9};
    vector<int> target = {1,0};
    EXPECT_EQ(target, solut.plusOne(input));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
