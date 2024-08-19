/* 题目描述: 118_杨辉三角

Given an integer numRows, return the first numRows of Pascal's triangle.

In Pascal's triangle, each number is the sum of the two numbers directly above it

Example 1:

Input: numRows = 5
Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]
Example 2:

Input: numRows = 1
Output: [[1]]

*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> result;
      for(int i =0; i<numRows; i++){
        vector<int> row(i+1, 1);
        for(int j=1; j<i; j++){
          row[j] = result[i-1][j-1] + result[i-1][j];
        }
        result.push_back(row);
      }
      return result;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<vector<int>> target = {{1},{1,1},{1,2,1},{1,3,3,1},{1,4,6,4,1}};
    EXPECT_EQ(target, solut.generate(5));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<vector<int>> target = {{1}};
    EXPECT_EQ(target, solut.generate(1));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
