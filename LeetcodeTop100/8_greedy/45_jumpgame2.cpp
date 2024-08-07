#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
      int jumps = 0;
      int currentMax = 0;
      int fathest = 0;

      for(int i=0; i<nums.size()-1; i++){
        fathest = max(fathest, i+nums[i]);

        if(i == currentMax){
          jumps++;
          currentMax = fathest;
          if(currentMax >= nums.size() -1){
            break;
          }
        }

      }
    return jumps;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> input = {2,3,1,1,4};
    EXPECT_EQ(2, solut.jump(input));
}
TEST(XXXTest, Case2){
    Solution solut;
    vector<int> input = {2,3,0,1,4};
    EXPECT_EQ(2, solut.jump(input));
}


int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
