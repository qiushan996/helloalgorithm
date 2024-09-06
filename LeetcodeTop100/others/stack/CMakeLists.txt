cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(227_BasicCalculatorII 227_BasicCalculatorII.cpp)
target_link_libraries(227_BasicCalculatorII ${GTEST_LIBRARIES} pthread)

add_executable(1047_removealladjacent 1047_removealladjacent.cpp)
target_link_libraries(1047_removealladjacent ${GTEST_LIBRARIES} pthread)

add_executable(150_EvaluatereversePolishnotation 150_EvaluatereversePolishnotation.cpp)
target_link_libraries(150_EvaluatereversePolishnotation ${GTEST_LIBRARIES} pthread)

add_executable(224_basicCalculatorHard 224_basicCalculatorHard.cpp)
target_link_libraries(224_basicCalculatorHard ${GTEST_LIBRARIES} pthread)
