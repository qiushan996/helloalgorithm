cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(344_ReverseString 344_ReverseString.cpp)
target_link_libraries(344_ReverseString ${GTEST_LIBRARIES} pthread)

add_executable(14_LongestCommonPrefix 14_LongestCommonPrefix.cpp)
target_link_libraries(14_LongestCommonPrefix ${GTEST_LIBRARIES} pthread)

add_executable(43_MultiplyStrings 43_MultiplyStrings.cpp)
target_link_libraries(43_MultiplyStrings ${GTEST_LIBRARIES} pthread)

add_executable(415_AddStrings 415_AddStrings.cpp)
target_link_libraries(415_AddStrings ${GTEST_LIBRARIES} pthread)

add_executable(151_ReverseWords 151_ReverseWords.cpp)
target_link_libraries(151_ReverseWords ${GTEST_LIBRARIES} pthread)

add_executable(557_ReverseWordsIII 557_ReverseWordsIII.cpp)
target_link_libraries(557_ReverseWordsIII ${GTEST_LIBRARIES} pthread)
