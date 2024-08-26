/* 题目描述: 852_山脉数组的峰值索引

You are given an integer mountain array arr of length n where the values increase to a peak element and then decrease.
Return the index of the peak element.

Your task is to solve it in O(log(n)) time complexity.

Example 1:
Input: arr = [0,1,0]
Output: 1

Example 2:
Input: arr = [0,2,1,0]
Output: 1

Example 3:
Input: arr = [0,10,5,2]
Output: 1
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l =0, r = arr.size()-1;
        while (l<r)
        {
          //std::cout<<"l: "<<arr[l]<<" r: "<<arr[r]<<std::endl;
          int mid = l + (r -l + 1)/2;
          if(arr[mid]>arr[mid-1] && arr[mid]>arr[mid+1]) return mid;

          else if(arr[mid]<arr[mid-1]) r = mid -1;
          else l = mid +1;
        }
        std::cout<<l<<" "<<r<<std::endl;
        return r;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> nums = {0,1,0};
    EXPECT_EQ(1, solut.peakIndexInMountainArray(nums));
}
TEST(XXXTest, Case2){
    Solution solut;
    vector<int> nums = {0,2,1,0};
    EXPECT_EQ(1, solut.peakIndexInMountainArray(nums));
}
TEST(XXXTest, Case3){
    Solution solut;
    vector<int> nums = {0,10,5,2};
    EXPECT_EQ(1, solut.peakIndexInMountainArray(nums));
}

TEST(XXXTest, Case4){
    Solution solut;
    vector<int> nums = {18,29,38,59,98,100,99,98,90};
    EXPECT_EQ(5, solut.peakIndexInMountainArray(nums));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
