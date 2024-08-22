cmake_minimum_required(VERSION 3.10)
project(MyProject)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 查找GTest包
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})


add_executable(array_66_PlusOne array_66_PlusOne.cpp)
target_link_libraries(array_66_PlusOne ${GTEST_LIBRARIES} pthread)

add_executable(array_724_FindOivotIndex array_724_FindOivotIndex.cpp)
target_link_libraries(array_724_FindOivotIndex ${GTEST_LIBRARIES} pthread)

add_executable(array_485_MaxConsecutiveOnes array_485_MaxConsecutiveOnes.cpp)
target_link_libraries(array_485_MaxConsecutiveOnes ${GTEST_LIBRARIES} pthread)

add_executable(array_498_DiagonalTraveser array_498_DiagonalTraveser.cpp)
target_link_libraries(array_498_DiagonalTraveser ${GTEST_LIBRARIES} pthread)

add_executable(array_59_SpiralMatrixII array_59_SpiralMatrixII.cpp)
target_link_libraries(array_59_SpiralMatrixII ${GTEST_LIBRARIES} pthread)

add_executable(289_GameofLife 289_GameofLife.cpp)
target_link_libraries(289_GameofLife ${GTEST_LIBRARIES} pthread)

add_executable(912_SortAnArray 912_SortAnArray.cpp)
target_link_libraries(912_SortAnArray ${GTEST_LIBRARIES} pthread)

add_executable(506_RelativeRanks 506_RelativeRanks.cpp)
target_link_libraries(506_RelativeRanks ${GTEST_LIBRARIES} pthread)

add_executable(80_removeDuplicates 80_removeDuplicates.cpp)
target_link_libraries(80_removeDuplicates ${GTEST_LIBRARIES} pthread)

add_executable(217_ContainsDuplicate 217_ContainsDuplicate.cpp)
target_link_libraries(217_ContainsDuplicate ${GTEST_LIBRARIES} pthread)

add_executable(179_LargestNumber 179_LargestNumber.cpp)
target_link_libraries(179_LargestNumber ${GTEST_LIBRARIES} pthread)
