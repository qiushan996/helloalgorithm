cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#调用utils
include_directories("${PROJECT_SOURCE_DIR}/utils")
add_subdirectory(utils)

add_executable(160_intersectlinkedlists 160_intersectlinkedlists.cpp)
target_link_libraries(160_intersectlinkedlists ${GTEST_LIBRARIES} pthread)

add_executable(206_reverselinkedlist 206_reverselinkedlist.cpp)
target_link_libraries(206_reverselinkedlist PUBLIC utils ${GTEST_LIBRARIES} pthread)
target_include_directories(206_reverselinkedlist PUBLIC 
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/utils")


add_executable(234_palindrome_linkedlists 234_palindrome_linkedlists.cpp)
target_link_libraries(234_palindrome_linkedlists ${GTEST_LIBRARIES} pthread)
add_executable(141_Cycle_linkedlists 141_Cycle_linkedlists.cpp)
target_link_libraries(141_Cycle_linkedlists ${GTEST_LIBRARIES} pthread)

add_executable(21_merge_two_sorted_linkedlists 21_merge_two_sorted_linkedlists.cpp)
target_link_libraries(21_merge_two_sorted_linkedlists PUBLIC utils   ${GTEST_LIBRARIES} pthread)
target_include_directories(21_merge_two_sorted_linkedlists PUBLIC 
                          "${PROJECT_BINARY_DIR}"
                          "${PROJECT_SOURCE_DIR}/utils")