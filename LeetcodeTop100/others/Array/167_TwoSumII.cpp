/* 题目描述: 167_两数之和-输入为有序数组

Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers, index1 and index2, added by one as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.

Example 1:
Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].

Example 2:
Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].

Example 3:
Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      vector<int> result;
      int left = 0, right = numbers.size()-1;
      //std::cout<<"left: "<<left<<"  right: "<<right<<endl;
      while (left<=right)
      {
        int tempsum = numbers[left] + numbers[right]; //
        if (target == tempsum)
        {
          result.push_back(left + 1);
          result.push_back(right + 1);
          return result;
        }
        else if(target < tempsum) right -=1;
        else left +=1;
      }
      return result;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> input = {2,7,11,15};
    vector<int> target = {1,2 };
    EXPECT_EQ(target, solut.twoSum(input, 9));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> input = {2,3,4};
    vector<int> target = {1,3 };
    EXPECT_EQ(target, solut.twoSum(input, 6));
}

TEST(XXXTest, Case3){
    Solution solut;
    vector<int> input = {-1, 0};
    vector<int> target = {1,2 };
    EXPECT_EQ(target, solut.twoSum(input,-1));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
