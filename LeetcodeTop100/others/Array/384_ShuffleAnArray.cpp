/* 题目描述: 384_打乱数组

Given an integer array nums, design an algorithm to randomly shuffle the array. All permutations of the array should be equally likely as a result of the shuffling.

Implement the Solution class:

Solution(int[] nums) Initializes the object with the integer array nums.
int[] reset() Resets the array to its original configuration and returns it.
int[] shuffle() Returns a random shuffling of the array.

Example 1:

Input
["Solution", "shuffle", "reset", "shuffle"]
[[[1, 2, 3]], [], [], []]
Output
[null, [3, 1, 2], [1, 2, 3], [1, 3, 2]]

Explanation
Solution solution = new Solution([1, 2, 3]);
solution.shuffle();    // Shuffle the array [1,2,3] and return its result.
                       // Any permutation of [1,2,3] must be equally likely to be returned.
                       // Example: return [3, 1, 2]
solution.reset();      // Resets the array back to its original configuration [1,2,3]. Return [1, 2, 3]
solution.shuffle();    // Returns the random shuffling of array [1,2,3]. Example: return [1, 3, 2]

*/
#include<vector>
#include<algorithm>
#include<ctime>
#include<gtest/gtest.h>

using namespace std;

class Solution {
    vector<int> arr;
    vector<int> original;
public:
    Solution(vector<int>& nums) {
        arr = nums;
        original = nums; 
    }
    
    vector<int> reset() {
        arr = original;
        return arr;
    }
    
    vector<int> shuffle() {
        //全排列问题
        for(int i = arr.size(); i>0; i--){
            int index  = rand()%(i+1);
            std::swap(arr[i], arr[index]);
        }
        return arr;
    }
};

//测试用例
TEST(XXXTest, Case1){
    vector<int> input = {1, 2, 3};
    Solution solut(input);
    
    solut.reset();
    EXPECT_EQ(input, solut.reset());
    //
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
