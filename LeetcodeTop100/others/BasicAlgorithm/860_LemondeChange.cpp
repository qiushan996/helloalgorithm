/* 题目描述: 860_柠檬水找零
At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.

Example 1:

Input: bills = [5,5,5,10,20]
Output: true
Explanation: 
From the first 3 customers, we collect three $5 bills in order.
From the fourth customer, we collect a $10 bill and give back a $5.
From the fifth customer, we give a $10 bill and a $5 bill.
Since all customers got correct change, we output true.
Example 2:

Input: bills = [5,5,10,10,20]
Output: false
Explanation: 
From the first two customers in order, we collect two $5 bills.
For the next two customers in order, we collect a $10 bill and give back a $5 bill.
For the last customer, we can not give the change of $15 back because we only have two $10 bills.
Since not every customer received the correct change, the answer is false.

*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
      //贪心算法
      // 1.	初始化：用来存储5美元和10美元的计数器。
      // 2.	遍历顾客支付的数组：
      // •	如果顾客支付了5美元，增加5美元计数器。
      // •	如果顾客支付了10美元，检查是否有5美元可以找零，有则减少5美元计数器，增加10美元计数器，没有则返回 false。
      // •	如果顾客支付了20美元，优先使用10美元和5美元进行找零，如果不足，尝试使用三个5美元找零，如果都不行，返回 false。

      int count_5 = 0, count_10 =0;
      for(int i=0; i<bills.size(); i++){
        if(bills[i]==5) count_5++;
        else if(bills[i] == 10){
          if(!count_5) return false;
          count_10++;
          count_5--;
        }
        else if(bills[i] == 20){
          if(count_10>0 && count_5>0){
            count_10--;
            count_5--;
          }else if(count_5>=3){
            count_5 -=3;
          }
          else return false;
        }
      }

      //完全都能找零，返回true
      return true;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    vector<int> bills = {5,5,5,10,20};
    EXPECT_TRUE(solut.lemonadeChange(bills));
}

TEST(XXXTest, Case2){
    Solution solut;
    vector<int> bills = {5,5,10,10,20};
    EXPECT_FALSE(solut.lemonadeChange(bills));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
