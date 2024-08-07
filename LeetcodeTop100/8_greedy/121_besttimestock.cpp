#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      // if(prices.size()<=1) return 0;
      // int maxprofile = 0, buy = 0, sell = 0;

      // for(int i=1; i<prices.size(); i++){
      //   if(prices[i] - prices[buy]>0){
      //     if(prices[i] - prices[buy] > maxprofile){
      //       maxprofile = prices[i] - prices[buy];
      //       sell = i;
      //     }
      //   }else{
      //     buy = i;
      //   }
      // }
      // return maxprofile;

      if (prices.empty()) return 0;       
      int minPrice = INT_MAX;
      int maxProfit = 0;
      
      for (int price : prices) {
        if (price < minPrice) {
            minPrice = price;
        } else if (price - minPrice > maxProfit) {
            maxProfit = price - minPrice;
        }
      }
        
        return maxProfit;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> input = {7,1,5,3,6,4};
    EXPECT_EQ(5, solut.maxProfit(input));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> input = {7,6,4,3,1};
    EXPECT_EQ(0, solut.maxProfit(input));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
