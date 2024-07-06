/*
题目描述：字母异位词分组

给定一个字符串数组，将字母异位词组合在一起。（字母异位词：字符串中的字母相同，顺序不同）
注意：
- 所有输入字符串为小写
- 不考虑输出的顺序

Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
*/

#include<string>
#include<unordered_map>
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;


vector<vector<string> > groupAnagrams(vector<string>& strs){
   // 使用unordered_map将排序后的字符串作为键，原始字符串列表作为值
    unordered_map<string, vector<string> > anagramGroups;

    // 遍历输入的字符串
    for (string& s : strs) {
        // 对字符串进行排序
        string sortedStr = s;
        sort(sortedStr.begin(), sortedStr.end());

        // 将原始字符串插入到对应排序字符串的键值中
        anagramGroups[sortedStr].push_back(s);
    }
  // 将map中的所有值收集到结果中
    vector<vector<string> > result;
    for (auto& group : anagramGroups) {
        result.push_back(group.second);
    }

    return result;
}

TEST(TestgroupAnagrams, TestOrdernal){
    // 示例输入
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    //不能这么直接初始化vector
    vector<vector<string> > expected;
    expected.push_back({"bat"});
    expected.push_back({"tan", "nat"});
    expected.push_back({"ate", "eat", "tea"});

    // 调用函数
    vector<vector<string>> result = groupAnagrams(strs);
    // if(result==expected) cout<<"result == excpected";
    // bool res = result==expected;
    EXPECT_EQ(result, expected)<<"测试用例1 失败";  //判断有误，无法忽略顺序
    // EXPECT_TRUE(res);
    
}

// TEST(TestgroupAnagrams, Test2Argv){
//       // 示例输入
//     vector<string> strs = {""};
//     vector<vector<string>> target = {[""]};

//     // 调用函数
//     vector<vector<string>> result = groupAnagrams(strs);
//     EXPECT_EQ(result, target);
// }

int main(int argc, char* argv[]){

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}