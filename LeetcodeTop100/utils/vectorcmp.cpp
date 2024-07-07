#include<string>
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

bool areEqualUnordered(std::vector<std::vector<std::string> > &vec1, std::vector<std::vector<std::string> > &vec2) {
    if (vec1.size() != vec2.size()) {
        return false;
    }

    for (auto& subvec : vec1) {
        std::sort(subvec.begin(), subvec.end());
    }

    for (auto& subvec : vec2) {
        std::sort(subvec.begin(), subvec.end());
    }

    std::sort(vec1.begin(), vec1.end());
    std::sort(vec2.begin(), vec2.end());

    return vec1 == vec2;
}


// bool areVectorEqual(vector<vector<string> > vec1, vector<vector<string> > vec2){

// }

TEST(VectorTest, StringVectorCase){
  std::vector<vector<string> > input1;
  std::vector<vector<string> > input2;
  input1.push_back({ "bat" });
  input1.push_back({"eat", "tea", "ate" });
  input1.push_back({  "tan", "nat"  });

  input2.push_back({ "bat" });
  input2.push_back({"tan", "nat" });
  input2.push_back({ "eat", "tea", "ate"});

  //EXPECT_EQ(input1, input2);
  EXPECT_TRUE(areEqualUnordered(input1, input2));
}


int main(int argc, char* argv[]){
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}