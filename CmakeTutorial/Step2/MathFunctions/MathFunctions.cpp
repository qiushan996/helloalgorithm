#include "MathFunctions.h"
#include<string>
#include<iostream>

void toString(std::string input)
{
  int len = input.length();
  for(int i=0; i<len-1; i++){
    std::cout<<input[i]<<"_";
  }
  std::cout<<std::endl;
  return ;
}