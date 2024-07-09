#include<iostream>
#include "TutorialConfig.h"


int main(int argc, char* argv[]){
  std::cout<<sizeof(size_t)<<std::endl;
  std::cout<<sizeof(int)<<std::endl;

  std::cout<<"Tutorial_VERSION_MINOR: "<<Tutorial_VERSION_MAJOR<<std::endl;
  
  //add C++11 features for excerise 2
  if(argc >2){
    const double inputValue = std::stod(argv[1]);
    std::cout<<inputValue<<std::endl;
  }


  return 0;
}