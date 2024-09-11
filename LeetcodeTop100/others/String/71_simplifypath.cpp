/* 题目描述: 71_路径简化
You are given an absolute path for a Unix-style file system, which always begins with a slash '/'. Your task is to transform this absolute path into its simplified canonical path.

The rules of a Unix-style file system are as follows:

A single period '.' represents the current directory.
A double period '..' represents the previous/parent directory.
Multiple consecutive slashes such as '//' and '///' are treated as a single slash '/'.
Any sequence of periods that does not match the rules above should be treated as a valid directory or file name. For example, '...' and '....' are valid directory or file names.
The simplified canonical path should follow these rules:

The path must start with a single slash '/'.
Directories within the path must be separated by exactly one slash '/'.
The path must not end with a slash '/', unless it is the root directory.
The path must not have any single or double periods ('.' and '..') used to denote current or parent directories.
Return the simplified canonical path.

Example 1:
Input: path = "/home/"

Output: "/home"

Explanation:

The trailing slash should be removed.

Example 2:

Input: path = "/home//foo/"

Output: "/home/foo"

Explanation:

Multiple consecutive slashes are replaced by a single one.

Example 3:

Input: path = "/home/user/Documents/../Pictures"

Output: "/home/user/Pictures"

Explanation:

A double period ".." refers to the directory up a level (the parent directory).

Example 4:

Input: path = "/../"

Output: "/"

Explanation:

Going one level up from the root directory is not possible.

Example 5:

Input: path = "/.../a/../b/c/../d/./"

Output: "/.../b/d"

Explanation:

"..." is a valid name for a directory in this problem.


*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
      string simplifyPath(string path) {
        std::vector<std::string> stack;
        std::stringstream ss(path);
        std::string part;
        
        // 分割路径并处理每个部分
        while (getline(ss, part, '/')) {
            if (part == "" || part == ".") {
                continue;  // 跳过空字符串和"."
            } else if (part == "..") {
                if (!stack.empty()) {
                    stack.pop_back();  // 返回上一级目录
                }
            } else {
                stack.push_back(part);  // 将目录压入栈
            }
        }

        // 构建简化后的路径
        std::string result = "/";
        for (int i = 0; i < stack.size(); ++i) {
            result += stack[i];
            if (i != stack.size() - 1) {
                result += "/";
            }
        }
        return result;
      }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    EXPECT_EQ("/home", solut.simplifyPath("/home/"));
    EXPECT_EQ("/home/foo", solut.simplifyPath("/home//foo/"));
    EXPECT_EQ("/home/user/Pictures", solut.simplifyPath("/home/user/Documents/../Pictures"));
    EXPECT_EQ("/", solut.simplifyPath("/../"));
    EXPECT_EQ("/.../b/d", solut.simplifyPath("/.../a/../b/c/../d/./"));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
