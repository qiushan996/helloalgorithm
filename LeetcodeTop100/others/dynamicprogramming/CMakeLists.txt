cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(62_uniquePaths 62_uniquePaths.cpp)
target_link_libraries(62_uniquePaths ${GTEST_LIBRARIES} pthread)

add_executable(64_MimPathSum 64_MimPathSum.cpp)
target_link_libraries(64_MimPathSum ${GTEST_LIBRARIES} pthread)
