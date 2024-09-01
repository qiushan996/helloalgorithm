/* 题目描述: 455_分发饼干

Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.
Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to maximize the number of your content children and output the maximum number.
假设你是一位很棒的家长，想给你的孩子一些饼干。但是，你应该给每个孩子最多一块饼干。
每个孩子 i 都有一个贪婪因子 g[i]，这是孩子会满意的饼干的最小尺寸；每个饼干 j 都有一个大小 s[j]。如果 s[j] >= g[i]，我们可以将饼干 j 分配给孩子 i，孩子 i 会感到满意。你的目标是最大化你满意的孩子的数量并输出最大数量。

Example 1:
Input: g = [1,2,3], s = [1,1]
Output: 1
Explanation: You have 3 children and 2 cookies. The greed factors of 3 children are 1, 2, 3. 
And even though you have 2 cookies, since their size is both 1, you could only make the child whose greed factor is 1 content.
You need to output 1.

Example 2:
Input: g = [1,2], s = [1,2,3]
Output: 2
Explanation: You have 2 children and 3 cookies. The greed factors of 2 children are 1, 2. 
You have 3 cookies and their sizes are big enough to gratify all of the children, 
You need to output 2.
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
      //贪心算法
      //使用贪心算法，先将孩子的胃口值和饼干大小进行排序，然后使用双指针或单指针从最小的尝试开始分配，尽可能地满足每个孩子。
      sort(g.begin(), g.end());
      sort(s.begin(), s.end());

      int child = 0, cookies = 0;
      while (child <g.size() && cookies<s.size())
      {
        if(g[child]<=s[cookies]) ++child;
        ++cookies;
      }
      return child;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> g = {1,2,3};
    vector<int> s = {1,1};
    EXPECT_EQ(1, solut.findContentChildren(g, s));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> g = {1,2};
    vector<int> s = {1,2,3};
    EXPECT_EQ(2, solut.findContentChildren(g, s));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
