/*题目描述: 289_生命游戏

According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."
根据维基百科的文章：“生命游戏，也简称为生命，是由英国数学家约翰·霍顿·康威于 1970 年设计的细胞自动机。”

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):
棋盘由一个 m x n 的单元格网格组成，每个单元格都有一个初始状态：存活（用 1 表示）或死亡（用 0 表示）。每个单元格使用以下四条规则（取自上述维基百科文章）与其八个邻居（水平、垂直、对角线）进行交互：

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
任何拥有少于两个活邻居的活细胞都会死亡，就像是由于细胞数量不足造成的一样。
任何拥有两个或三个活邻居的活细胞都会存活到下一代。
任何拥有三个以上活邻居的活细胞都会死亡，就像是由于细胞数量过剩造成的一样。
任何拥有恰好三个活邻居的死细胞都会变成活细胞，就像是通过繁殖造成的一样。

Example1:
Input: board = [[0,1,0],[0,0,1],[1,1,1],[0,0,0]]
Output: [[0,0,0],[1,0,1],[0,1,1],[0,1,0]]

Example2:
Input: board = [[1,1],[1,0]]
Output: [[1,1],[1,1]]
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
      int m = board.size(), n = board[0].size();

      //计算周围活细胞的数量
      auto countNeighbors = [&](int row, int col){
        int count = 0;
        for(int i = std::max(row-1,0);i<=std::min(row+1, m-1); ++i){
          for(int j = std::max(col - 1, 0); j<=std::min(col+1, n-1); ++j){
            if(i== row && j == col) continue;
            if(board[i][j] == 1 || board[i][j] == 2) count++;
          }
        }
        return count;
      };

      //更新状态
      for(int i=0; i<m; i++){
        for(int j =0;j<n; j++){
          int liveNeighbors = countNeighbors(i, j);
          if(board[i][j] == 1 && (liveNeighbors <2 || liveNeighbors >3)) 
            board[i][j] = 2;
          if(board[i][j] == 0 && liveNeighbors ==3)
            board[i][j] = 3;
        }
      }
      //解码状态
      for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
          board[i][j] %= 2;
        }
      }
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<vector<int>> input = {{0,1,0}, {0,0,1}, {1,1,1},{0,0,0}};
    vector<vector<int>> target = {{0,0,0}, {1,0,1}, {0,1,1},{0,1,0}};
    solut.gameOfLife(input);
    EXPECT_EQ(target, input);
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<vector<int>> input = {{1,1}, {1,0} };
    vector<vector<int>> target = {{1,1}, {1,1} };
    solut.gameOfLife(input);
    EXPECT_EQ(target, input);
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
