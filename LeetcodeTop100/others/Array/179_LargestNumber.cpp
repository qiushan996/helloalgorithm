/*题目描述: 179_最大数

Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
Since the result may be very large, so you need to return a string instead of an integer.
给定一个非负整数列表 nums，将它们排列成最大的数字并返回它。
由于结果可能非常大，所以需要返回一个字符串而不是整数。

Example 1:
Input: nums = [10,2]
Output: "210"

Example 2:
Input: nums = [3,30,34,5,9]
Output: "9534330"

*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
      std::string result;
      int len = nums.size();

      vector<std::string> asString;
      for(int num:nums){
        asString.push_back(std::to_string(num));
      }

      //排序
      std::sort(asString.begin(), asString.end(), [](const std::string &a, const std::string &b){
        return a + b > b + a;
      });
      
      //后相加
      for(std::string str: asString){
        result +=str;
      }

      if(result[0] == 0) return "0";
      return result;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> input = {10, 2};
    std::string target = "210";
    EXPECT_EQ(target, solut.largestNumber(input));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> input = {3,30,34,5,9};
    std::string target = "9534330";
    EXPECT_EQ(target, solut.largestNumber(input));
}
int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
