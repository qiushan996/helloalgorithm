/*
题目描述：

给定一个整数数组和一个目标整数，返回数组中两个元素的坐标，这两个数组元素相加等于目标数。
您可以假定每个输入都有一个解，而且同一元素不能使用两次。
您可以按任何顺序返回答案。

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
*/


#include<iostream>
#include<vector>
#include<string>
#include<sstream>

//googletest 单元测试
#include<gtest/gtest.h>

// //读取输入1:
// std::vector<int> getinput(){
//   std::cout<<"输入连续的整数："<<std::endl;
//   std::vector<int>  result ;
//   int input;

//   while (std::cin>>input)
//   {
//     result.push_back(input);
//     if(input == 'q') break;  //结束表示q
//   }
  
//   std::cin.clear();
//   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //
//   return result;
// }

//two sum function
std::vector<int> twosum(std::vector<int>& input, int target){
  std::cout<<input.size()<<std::endl;
  //定一个返回值
  std::vector<int> res;
  //for(auto i: input) std::cout<<i<<",";
  //两个for循环
  for (size_t i = 0; i < input.size()-1; i++)
  {
    for (size_t j = i+1; j < input.size(); j++)
    {
      if(input[i] + input[j] == target)
      {
        res.push_back(i);
        res.push_back(j);
        return res;
      }
    }
  }
  return res;
};

// //读取输入
// std::vector<int> get_input() {
//     std::cout << "输入连续的整数（按回车结束）：\n";
//     std::vector<int> result;
//     std::string inputLine;

//     while (true) {
//         std::getline(std::cin, inputLine); // 读取整行输入
//         if (inputLine.empty()) { // 如果输入为空行，则结束输入
//             break;
//         }

//         std::istringstream stream(inputLine); // 使用字符串流处理输入
//         int number;
//         while (stream >> number) { // 从字符串流中提取整数
//             result.push_back(number);
//         }
//     }

//     return result;
// }


//测试函数
TEST(TwoSumTest, TestCases){
  // Test case 1
  std::vector<int> input1 = {2, 7, 11, 15};
  int target1 = 9;
  std::vector<int> result1 = twosum(input1, target1);
  std::vector<int> expected1 = {0, 1};
  EXPECT_EQ(result1, expected1);

  //Test case 2
  std::vector<int> input2 = {3,2,4};
  int target2 = 6;
  std::vector<int> result2 = twosum(input2, target2);
  std::vector<int> expected2 = {1,2};
  EXPECT_EQ(result2, expected2);
}

TEST(TwoSumTest, TestOnly2Argv){
  //Test case 3
  std::vector<int> input3 = {3,3 };
  int target3 =6;
  std::vector<int>  result3 = twosum(input3, target3);
  std::vector<int>  expected3 = {0,1 };
  EXPECT_EQ(result3, expected3);
}

int main(int argc, char* argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}