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

//判断两个vector是否包含相同的值
bool areEqualUnordered(std::vector<std::vector<std::string> > &vec1, std::vector<std::vector<std::string> > &vec2) {
    if (vec1.size() != vec2.size()) {
        return false;
    }

    for (auto& subvec : vec1) {
        std::sort(subvec.begin(), subvec.end());
    }

    for (auto& subvec : vec2) {
        std::sort(subvec.begin(), subvec.end());
    }

    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());

    return vec1 == vec2;
}


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
    std::sort(result.begin(), result.end());
    //std::sort(expected.begin(), expected.end());
    //EXPECT_EQ(result, expected);  //判断有误，无法忽略顺序
    EXPECT_TRUE(areEqualUnordered(result, expected));
    
}

TEST(TestgroupAnagrams, TestNullArgv){
      // 示例输入
    vector<string> strs ;
    strs.push_back({""});
    vector<vector<string>> target ;
    target.push_back({""});

    // 调用函数
    vector<vector<string>> result = groupAnagrams(strs);
    EXPECT_EQ(result, target);
}

TEST(TestgroupAnagrams, Test2Argv){
      // 示例输入
    vector<string> strs ;
    strs.push_back({"a"});
    vector<vector<string>> target ;
    target.push_back({"a"});

    // 调用函数
    vector<vector<string>> result = groupAnagrams(strs);
    EXPECT_EQ(result, target);
}

int main(int argc, char* argv[]){

  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}