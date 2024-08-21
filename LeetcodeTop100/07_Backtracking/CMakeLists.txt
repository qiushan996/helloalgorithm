cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(46_permutations 46_permutations.cpp)
target_link_libraries(46_permutations ${GTEST_LIBRARIES} pthread)

add_executable(78_subsets 78_subsets.cpp)
target_link_libraries(78_subsets ${GTEST_LIBRARIES} pthread)

add_executable(17_phonenumstr 17_phonenumstr.cpp)
target_link_libraries(17_phonenumstr ${GTEST_LIBRARIES} pthread)

add_executable(39_combinesum 39_combinesum.cpp)
target_link_libraries(39_combinesum ${GTEST_LIBRARIES} pthread)

add_executable(79_wordsearch 79_wordsearch.cpp)
target_link_libraries(79_wordsearch ${GTEST_LIBRARIES} pthread)

add_executable(22_generateparentheses 22_generateparentheses.cpp)
target_link_libraries(22_generateparentheses ${GTEST_LIBRARIES} pthread)

add_executable(131_palindromeoartition 131_palindromeoartition.cpp)
target_link_libraries(131_palindromeoartition ${GTEST_LIBRARIES} pthread)
