/* 题目描述: 41_缺失的第一个正整数
Given an unsorted integer array nums. Return the smallest positive integer that is not present in nums.
You must implement an algorithm that runs in O(n) time and uses O(1) auxiliary space.

Example 1:
Input: nums = [1,2,0]
Output: 3
Explanation: The numbers in the range [1,2] are all in the array.
Example 2:
Input: nums = [3,4,-1,1]
Output: 2
Explanation: 1 is in the array but 2 is missing.
Example 3:

Input: nums = [7,8,9,11,12]
Output: 1
Explanation: The smallest positive integer 1 is missing.
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    //思路
    // 1.	归位操作：通过一个循环，我们试图将数组中的每个正数放到其数值对应的索引位置（即数值1放在索引0的位置，数值2放在索引1的位置，以此类推）。这是通过不断交换来实现的。
    // 2.	查找缺失的正数：在完成上述归位操作后，我们再次遍历数组，第一个索引位置不正确的就是缺失的最小正数。
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            while (nums[i] > 0 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        
        return n + 1;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> nums = {1,2,0};
    EXPECT_EQ(3, solut.firstMissingPositive(nums));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> nums = {3,4,-1,1};
    EXPECT_EQ(2, solut.firstMissingPositive(nums));
}
TEST(XXXTest, Case3){
    Solution solut;
    vector<int> nums = {7,8,9,11,12};
    EXPECT_EQ(1, solut.firstMissingPositive(nums));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
