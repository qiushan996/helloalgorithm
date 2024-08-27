/*题目描述: 4_寻找两个正序数组中的中位数（困难）
Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).

Example 1:
Input: nums1 = [1,3], nums2 = [2]
Output: 2.00000
Explanation: merged array = [1,2,3] and median is 2.

Example 2:
Input: nums1 = [1,2], nums2 = [3,4]
Output: 2.50000
Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // GPT解答
        // 保证nums1是较短的数组
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int totalLeft = (m + n + 1) / 2;

        int left = 0;
        int right = m;

        while (left < right) {
            int i = left + (right - left + 1) / 2;
            int j = totalLeft - i;
            if (nums1[i - 1] > nums2[j]) {
                right = i - 1;
            } else {
                left = i;
            }
        }

        int i = left;
        int j = totalLeft - i;
        int nums1LeftMax = i == 0 ? INT_MIN : nums1[i - 1];
        int nums1RightMin = i == m ? INT_MAX : nums1[i];
        int nums2LeftMax = j == 0 ? INT_MIN : nums2[j - 1];
        int nums2RightMin = j == n ? INT_MAX : nums2[j];

        if ((m + n) % 2 == 1) {
            return std::max(nums1LeftMax, nums2LeftMax);
        } else {
            return (std::max(nums1LeftMax, nums2LeftMax) + std::min(nums1RightMin, nums2RightMin)) / 2.0;
        }
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> num1 = {1,3};
    vector<int> num2 = {2};
    EXPECT_EQ(2.0, solut.findMedianSortedArrays(num1, num2));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> num1 = {1,2};
    vector<int> num2 = {3,4};
    EXPECT_EQ(2.5, solut.findMedianSortedArrays(num1, num2));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
