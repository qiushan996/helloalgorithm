#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
      vector<int> lastindex(26,0);

      for(int i = 0; i<s.length(); i++){
        lastindex[s[i] - 'a'] = i;
      }      

      vector<int> result;
      int start = 0, end = 0;
      for(int i = 0; i < s.length() ; i++){
        end = max(end, lastindex[s[i] - 'a']);
        if(i == end){
          result.push_back(i - start + 1);
          start = i + 1;
        }
      }
      return result;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    string  input = "ababcbacadefegdehijhklij";
    vector<int>  result = solut.partitionLabels(input);
    vector<int> target = {9, 7,8}; 
    EXPECT_EQ(target, result);
}

TEST(XXXTest, Case2){
    Solution solut;
    string  input = "eccbbbbdec";
    vector<int>  result = solut.partitionLabels(input);
    vector<int> target = {10}; 
    EXPECT_EQ(target, result);
}
TEST(XXXTest, Case3){
    Solution solut;
    string  input = "caedbdedda";
    vector<int>  result = solut.partitionLabels(input);
    vector<int> target = {1, 9}; 
    EXPECT_EQ(target, result);
}


int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
