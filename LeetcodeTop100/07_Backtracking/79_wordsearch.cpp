/* 题目描述: 79_WordSearch_搜索单词

Example 1：
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCCED"
Output: true

Example 2：
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "SEE"
Output: true

Example 3：
Input: board = [["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]], word = "ABCB"
Output: false
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
      int rows = board.size();
      if(rows == 0) return false;
      int cols = board[0].size();

      for(int i=0; i< rows; ++i){
        for(int j = 0; j < cols; ++j){
          if(trackback(board, word, i, j ,0)){
            return true;
          }
        }
      }
      return false;
    }
private:
  bool trackback(vector<vector<char>>& board, string& word, int i, int j ,int index){
    if(index == word.size()) return true;
    //越界或者没找到返回false
    if(i<0||i>=board.size() || j<0||j>=board[0].size() || board[i][j]!=word[index]){
      return false;
    }

    char temp = board[i][j];
    board[i][j] = '#';

    bool found = trackback(board,word, i+1, j, index+1)
              || trackback(board,word, i-1, j, index +1)
              || trackback(board, word, i, j+1, index +1)
              || trackback(board,word, i , j-1, index +1);
    board[i][j] = temp;
    return found;
  }
};

//测试用例
TEST(XXXTest, Case1){
  vector<vector<char>> input = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
  Solution solut;
  bool result = solut.exist(input, "ABCCED");
  EXPECT_TRUE(result);
}

TEST(XXXTest, Case2){
  vector<vector<char>> input = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
  Solution solut;
  bool result = solut.exist(input, "SEE");
  EXPECT_TRUE(result);
}

TEST(XXXTest, Case3){
  vector<vector<char>> input = {{'A','B','C','E'},{'S','F','C','S'},{'A','D','E','E'}};
  Solution solut;
  bool result = solut.exist(input, "ABCB");
  EXPECT_FALSE(result );
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
