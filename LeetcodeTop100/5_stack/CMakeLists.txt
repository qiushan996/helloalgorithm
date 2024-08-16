cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(20_ValidParentheses 20_ValidParentheses.cpp)
target_link_libraries(20_ValidParentheses ${GTEST_LIBRARIES} pthread)

add_executable(394_decodeString 394_decodeString.cpp)
target_link_libraries(394_decodeString ${GTEST_LIBRARIES} pthread)

add_executable(739_dailyTemperatures 739_dailyTemperatures.cpp)
target_link_libraries(739_dailyTemperatures ${GTEST_LIBRARIES} pthread)
