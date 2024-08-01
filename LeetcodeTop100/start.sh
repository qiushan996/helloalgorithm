#!/bin/bash

# 检查参数数量
if [ $# -ne 2 ]; then
    echo "Usage: $0 <directory> <filename>"
    exit 1
fi

# 获取参数
directory=$1
filename=$2

# 检查目录是否存在，如果不存在则创建
if [ ! -d "$directory" ]; then
    mkdir -p "$directory"
fi

# 创建文件并添加内容
cat > "$directory/$filename" << EOL
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
};

//测试用例
TEST(XXXTest, Case1){
    EXPECT_EQ( );
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
EOL

echo "File $filename created in $directory"

# 修改或创建CMakeLists.txt文件
cmake_file="$directory/CMakeLists.txt"

# 检查CMakeLists.txt文件是否存在
if [ ! -f "$cmake_file" ]; then
    echo "CMakeLists.txt not found in $directory. Creating a new one."
    # 创建一个新的CMakeLists.txt文件并添加基本内容
    cat > "$cmake_file" << EOL
cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GTest包
find_package(GTest REQUIRED)
include_directories(\${GTEST_INCLUDE_DIRS})

EOL
fi

# 添加内容到CMakeLists.txt
echo "" >> "$cmake_file"
echo "add_executable(${filename%.*} ${filename})" >> "$cmake_file"
echo "target_link_libraries(${filename%.*} \${GTEST_LIBRARIES} pthread)" >> "$cmake_file"

echo "CMakeLists.txt updated"