代码模版:

```c++
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

class Solution {
public:
};

//测试用例
TEST(XXXTest, Case1){
  EXPECT_EQ(target, result);
}

TEST(XXXTest, Case2){
  EXPECT_EQ();
}

TEST(XXXTest, Case3){
  EXPECT_EQ();
}

int main(int argc, char* argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

```


修改 CMakeLists.txt  
```shell
add_executable(maxsubarray   53_MaxSubArray.cpp)

target_link_libraries(maxsubarray  ${GTEST_LIBRARIES}  pthread)
```