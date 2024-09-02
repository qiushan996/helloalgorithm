/* 题目描述: 51_N皇后
The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
不能互相攻击指的是任何两个皇后都不能处于同一条横线、纵线或者斜线上。

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.

Example1:
Input: n = 4
Output: [[".Q..","...Q","Q...","..Q."],["..Q.","Q...","...Q",".Q.."]]
Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above

Example2:
Input: n = 1
Output: [["Q"]]

*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
    //这是一个典型的回溯问题，可以通过递归来实现。我们需要维护当前列、两个方向的对角线上的占用情况，以确保不会放置两个能相互攻击的皇后。
    // 1.	定义数据结构：用三个集合分别记录哪些列、哪两种对角线上已经放置了皇后。
    // •	cols: 存储已被占用的列。
    // •	diag1: 存储主对角线（从左上到右下）已被占用的情况。
    // •	diag2: 存储副对角线（从右上到左下）已被占用的情况。
    // 2.	递归函数：
    // •	如果行号等于 n，说明找到了一个解，将其添加到结果中。
    // •	否则，尝试在当前行的每一列放置皇后，如果这一列和两个对角线都没有被其他皇后占用，则放置皇后。
    // •	递归调用下一行。
    // •	回溯：撤销当前行的皇后，尝试下一个位置。
    // 3.	输出结果：将所有解转换为期望的棋盘格式输出。
    vector<vector<string>> result;
    vector<bool> col(n, false);
    vector<bool> dig1(2*n, false);
    vector<bool> dig2(2*n, false);
    vector<string> board(n, string(n, '.'));
    backtrack(result, board,0, n, col,dig1, dig2);
    return result;

    }

    void backtrack(vector<vector<string>>& result, vector<string>& board, int row, int n, 
                  vector<bool>& cols, vector<bool>& dig1, vector<bool>& dig2 ){
                    //终止条件
                    if(n==row){
                      result.push_back(board);
                      return;
                    }

                    for(int col=0; col<n; col++){
                      int d1 = col - row +n;
                      int d2 = col + row;
                      if(!cols[col]&& !dig1[d1] && !dig2[d2]){
                          board[row][col] = 'Q';
                          cols[col] = dig2[d2] = dig1[d1] = true;
                          backtrack(result, board, row+1, n, cols, dig1, dig2);
                          board[row][col] = '.';
                          cols[col] = dig2[d2] = dig1[d1] = false;
                        }
                    }

                  }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<vector<string>> target = {{".Q..","...Q","Q...","..Q."}, {"..Q.","Q...","...Q",".Q.."}};
    EXPECT_EQ(target, solut.solveNQueens(4));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<vector<string>> target = {{"Q"}};
    EXPECT_EQ(target, solut.solveNQueens(1));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
