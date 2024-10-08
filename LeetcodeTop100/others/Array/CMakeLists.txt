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

add_executable(384_ShuffleAnArray 384_ShuffleAnArray.cpp)
target_link_libraries(384_ShuffleAnArray ${GTEST_LIBRARIES} pthread)

add_executable(561_ArrayPartition 561_ArrayPartition.cpp)
target_link_libraries(561_ArrayPartition ${GTEST_LIBRARIES} pthread)

add_executable(704_BinarySearch 704_BinarySearch.cpp)
target_link_libraries(704_BinarySearch ${GTEST_LIBRARIES} pthread)

add_executable(374_GuessNumber 374_GuessNumber.cpp)
target_link_libraries(374_GuessNumber ${GTEST_LIBRARIES} pthread)

add_executable(167_TwoSumII 167_TwoSumII.cpp)
target_link_libraries(167_TwoSumII ${GTEST_LIBRARIES} pthread)

add_executable(162_FindPeekElement 162_FindPeekElement.cpp)
target_link_libraries(162_FindPeekElement ${GTEST_LIBRARIES} pthread)

add_executable(154_FindMinSortedArrayII 154_FindMinSortedArrayII.cpp)
target_link_libraries(154_FindMinSortedArrayII ${GTEST_LIBRARIES} pthread)

add_executable(81_SearchRotatedArray 81_SearchRotatedArray.cpp)
target_link_libraries(81_SearchRotatedArray ${GTEST_LIBRARIES} pthread)

add_executable(852_PeakIndexMountainArray 852_PeakIndexMountainArray.cpp)
target_link_libraries(852_PeakIndexMountainArray ${GTEST_LIBRARIES} pthread)

add_executable(04_medianOfTowArrays 04_medianOfTowArrays.cpp)
target_link_libraries(04_medianOfTowArrays ${GTEST_LIBRARIES} pthread)

add_executable(69_sqrt 69_sqrt.cpp)
target_link_libraries(69_sqrt ${GTEST_LIBRARIES} pthread)

add_executable(50_Pow 50_Pow.cpp)
target_link_libraries(50_Pow ${GTEST_LIBRARIES} pthread)

add_executable(400_NthDigit 400_NthDigit.cpp)
target_link_libraries(400_NthDigit ${GTEST_LIBRARIES} pthread)

add_executable(26_removeDuplicatesArray 26_removeDuplicatesArray.cpp)
target_link_libraries(26_removeDuplicatesArray ${GTEST_LIBRARIES} pthread)

add_executable(349_IntersectionOfTwoArray 349_IntersectionOfTwoArray.cpp)
target_link_libraries(349_IntersectionOfTwoArray ${GTEST_LIBRARIES} pthread)

add_executable(1343_NumberOfSubarray 1343_NumberOfSubarray.cpp)
target_link_libraries(1343_NumberOfSubarray ${GTEST_LIBRARIES} pthread)

add_executable(209_MinimSize 209_MinimSize.cpp)
target_link_libraries(209_MinimSize ${GTEST_LIBRARIES} pthread)

add_executable(713_SubarrayLessK 713_SubarrayLessK.cpp)
target_link_libraries(713_SubarrayLessK ${GTEST_LIBRARIES} pthread)

add_executable(643_MaximumAverage 643_MaximumAverage.cpp)
target_link_libraries(643_MaximumAverage ${GTEST_LIBRARIES} pthread)

add_executable(57_insertinterval 57_insertinterval.cpp)
target_link_libraries(57_insertinterval ${GTEST_LIBRARIES} pthread)

add_executable(452_mimnumofArrows 452_mimnumofArrows.cpp)
target_link_libraries(452_mimnumofArrows ${GTEST_LIBRARIES} pthread)

add_executable(350_intersection_TwoArray 350_intersection_TwoArray.cpp)
target_link_libraries(350_intersection_TwoArray ${GTEST_LIBRARIES} pthread)

add_executable(448_FindAllNumDispear 448_FindAllNumDispear.cpp)
target_link_libraries(448_FindAllNumDispear ${GTEST_LIBRARIES} pthread)

add_executable(819_mostcommonword 819_mostcommonword.cpp)
target_link_libraries(819_mostcommonword ${GTEST_LIBRARIES} pthread)
