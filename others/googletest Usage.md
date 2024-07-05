
​C++单元测试框架有cppunit, boost.Test googletest等, 其中googletest简称gtest，具有跨平台性及丰富的特性。以下主要介绍gtest的使用。

github: https://github.com/google/googletest

wiki手册: https://google.github.io/googletest/


### 1、Googletest的编译（Mac OS）

前提： 安装 Homebrew

` /bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
`

使用homebrew安装googletest：

`brew install googletest
`

### 2、Googletest的使用

**2.1 编写 CMakeLists.txt 文件**

假设你有一个测试文件 test.cpp，你可以创建一个 CMakeLists.txt 文件来编译和运行测试。以下是一个示例 CMakeLists.txt 文件：
```c++
cmake_minimum_required(VERSION 3.10)
project(MyTests)

# 使用 C++ 标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# 查找 GoogleTest 库
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# 添加测试文件
add_executable(runTests test.cpp)

# 链接 GoogleTest 库
target_link_libraries(runTests ${GTEST_LIBRARIES} pthread)

```
**2.2 编写测试文件**

创建一个 test.cpp 文件，并编写一个简单的测试用例：
```c++
#include <gtest/gtest.h>

// 示例测试函数
TEST(SampleTest, AssertionTrue) {
    EXPECT_EQ(1, 1);
}

// main 函数初始化 GoogleTest
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

```

**2.3 编译和运行测试**

创建构建目录：在项目的根目录下创建一个构建目录：
```
mkdir build 
cd build
```

生成构建文件：使用 CMake 生成构建文件
```
cmake ..
```

编译项目：
```
make
```

测试运行：运行生成的测试可执行文件
```
./runTests
```
