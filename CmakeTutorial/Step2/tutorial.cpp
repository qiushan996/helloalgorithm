#include"MathFunctions/MathFunctions.h"
#include<iostream>
#include<string>
using namespace std;

int main(int argc, char* argv[]){

  string str = "Step 2: Adding a Library";
  std::cout<<"case1: "<<std::endl;
  toString(str);

  int case2 = 81;
  std::cout<<"case 2: "<<std::endl;
  double sqrtcase2 = ssqrt(case2);
  cout<<"The square root of  "<<case2<<" is: "<<sqrtcase2<<endl;
  return 0;
}