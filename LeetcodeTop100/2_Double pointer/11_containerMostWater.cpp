/*题目描述:  盛水最多的容器

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.

给定一个长度为 n 的整数数组 height。绘制 n 条垂直线，使得第 i 条线的两个端点分别为 (i, 0) 和 (i, height[i])。找到两条与 x 轴一起构成容器的线，使得容器包含最多的水。返回容器可以存储的最大水量。


Notice that you may not slant the container.


Example 1:
Input: height = [1,8,6,2,5,4,8,3,7]
Output: 49
Explanation: The above vertical lines are represented by array [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section) the container can contain is 49.

Example 2:
Input: height = [1,1]
Output: 1
*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;


class Solution {
public:
    int maxArea(vector<int>& height) {
      int Maxwater = 0; //最大的水的容量
      int left =0;
      int right = height.size()-1;

      while(left<right){
        //计算水的容量
        int width = right -left;
        int heigh = min(height[left], height[right]);

        int water = width * heigh;

        //更新水的容量
        Maxwater = max(Maxwater, water);

        //移动指针
        if(height[left]<height[right]) left++;
        else right--;

      }
      return Maxwater;
    }
};

TEST(ContainerTest, case1){
  vector<int> input1 = {1,8,6,2,5,4,8,3,7};
  int target = 49;
  Solution solut;
  int result = solut.maxArea(input1);
  EXPECT_EQ(target,result);
}

TEST(ContainerTest, case2){
  vector<int> input1 = {1,1};
  int target = 1;
  Solution solut;
  int result = solut.maxArea(input1);
  EXPECT_EQ(target,result);
}

int main(int argc, char* argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}