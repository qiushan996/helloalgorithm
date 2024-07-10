#include"MathFunctions/MathFunctions.h"
#include<iostream>
#include<string>
using namespace std;

int main(int argc, char* argv[]){

  string str = "Step 2: Adding a Library";
  std::cout<<"case1: "<<std::endl;
  toString(str);

  try{
    int case2 = stoi(argv[1]);
    std::cout<<"case 2: "<<std::endl;
    double sqrtcase2 = ssqrt(case2);
    cout<<case2<<" is "<<sqrtcase2<<endl;

  }catch (const std::invalid_argument& e) {
        std::cerr << "Invalid argument: " << argv[1] << " is not a valid number" << std::endl;
        return 1;
  } catch (const std::out_of_range& e) {
      std::cerr << "Out of range: " << argv[1] << " is too large" << std::endl;
      return 1;
  }
  return 0;
}