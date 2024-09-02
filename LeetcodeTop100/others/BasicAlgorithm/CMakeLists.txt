cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(1925_countsquare 1925_countsquare.cpp)
target_link_libraries(1925_countsquare ${GTEST_LIBRARIES} pthread)

add_executable(1450_NumberOfStudents 1450_NumberOfStudents.cpp)
target_link_libraries(1450_NumberOfStudents ${GTEST_LIBRARIES} pthread)

add_executable(23_MergekSortedLists 23_MergekSortedLists.cpp)
target_link_libraries(23_MergekSortedLists ${GTEST_LIBRARIES} pthread)

add_executable(504_Base7 504_Base7.cpp)
target_link_libraries(504_Base7 ${GTEST_LIBRARIES} pthread)

add_executable(190_ReverseBits 190_ReverseBits.cpp)
target_link_libraries(190_ReverseBits ${GTEST_LIBRARIES} pthread)

add_executable(371_SumofTwoInter 371_SumofTwoInter.cpp)
target_link_libraries(371_SumofTwoInter ${GTEST_LIBRARIES} pthread)

add_executable(338_CountingBits 338_CountingBits.cpp)
target_link_libraries(338_CountingBits ${GTEST_LIBRARIES} pthread)

add_executable(455_AssignCookie 455_AssignCookie.cpp)
target_link_libraries(455_AssignCookie ${GTEST_LIBRARIES} pthread)

add_executable(435_NonoverlappingIntervals 435_NonoverlappingIntervals.cpp)
target_link_libraries(435_NonoverlappingIntervals ${GTEST_LIBRARIES} pthread)

add_executable(860_LemondeChange 860_LemondeChange.cpp)
target_link_libraries(860_LemondeChange ${GTEST_LIBRARIES} pthread)

add_executable(561_ArrayPartion 561_ArrayPartion.cpp)
target_link_libraries(561_ArrayPartion ${GTEST_LIBRARIES} pthread)

add_executable(1400_ConstructKPalindromeStr 1400_ConstructKPalindromeStr.cpp)
target_link_libraries(1400_ConstructKPalindromeStr ${GTEST_LIBRARIES} pthread)

add_executable(78_Subsets 78_Subsets.cpp)
target_link_libraries(78_Subsets ${GTEST_LIBRARIES} pthread)

add_executable(51_NQueens 51_NQueens.cpp)
target_link_libraries(51_NQueens ${GTEST_LIBRARIES} pthread)

add_executable(47_PermutationsII 47_PermutationsII.cpp)
target_link_libraries(47_PermutationsII ${GTEST_LIBRARIES} pthread)

add_executable(784_LetterCasePermulation 784_LetterCasePermulation.cpp)
target_link_libraries(784_LetterCasePermulation ${GTEST_LIBRARIES} pthread)
