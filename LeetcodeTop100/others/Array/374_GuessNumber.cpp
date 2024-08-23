/* 题目描述: 374_猜数字大小

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.
我从 1 到 n 中选一个数字。你必须猜出我选了哪个数字。
Every time you guess wrong, I will tell you whether the number I picked is higher or lower than your guess.

Example 1:
Input: n = 10, pick = 6
Output: 6

Example 2:
Input: n = 1, pick = 1
Output: 1

Example 3:
Input: n = 2, pick = 1
Output: 1
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int guessNumber(int n, int pick) {
        int left = 0, right = n;
        while (left<=right)
        {
          int mid = (left + right)/2;
          int res = guess(mid);
          if(res == 0) return mid;
          else if(res ==-1) right = mid -1;
          else left = mid + 1;
        }
      return -1;
    }

private:
  /** 
   * Forward declaration of guess API.
   * @param  num   your guess
   * @return 	     -1 if num is higher than the picked number
   *			      1 if num is lower than the picked number
  *               otherwise return 0
  * int guess(int num);
  */
  int guess(int num){
    int pick = 6;
    if(num>pick)return -1;
    else if(num<pick) return 1;
    else return 0;
  }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    //EXPECT_EQ(target, result);
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
