/*题目描述: 344_反转字符串
Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

Example 1:
Input: s = ['h','e','l','l','o']
Output: ['o','l','l','e','h']

Example 2:
Input: s = ['H','a','n','n','a','h']
Output: ['h','a','n','n','a','H']
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
      //时间复杂度: O(n)
      int len = s.size();
        // for(int i=0; i<len /2; i++){
        //   std::swap(s[i], s[len -1-i]);
        // }

      //
      int left =0, right = len -1;
      while (left <right)
      {
        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        left++;
        right--;
      }
      

    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<char> nums = {'h','e','l','l','o'};
    vector<char> target = {'o','l','l','e','h'};
    solut.reverseString(nums);
    EXPECT_EQ(target, nums);
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<char> nums = {'H','a','n','n','a','h'};
    vector<char> target = {'h','a','n','n','a','H'};
    solut.reverseString(nums);
    EXPECT_EQ(target, nums);
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
