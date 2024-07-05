#include<vector>
#include<iostream>

void displaylist(std::vector<int> lists){
  for(int x: lists){
    std::cout<<x<<" ";
  }
  std::cout<<std::endl;
} 

void displaylist(std::vector<std::string> x){
  for(std::string str: x){
    std::cout<<str<<" ";
  }
  std::cout<<std::endl;
}

int  main(){
  //初始化
  std::vector<std::string> name = {"John", "Smith", "Zhang", "Liu"};
  std::vector<int> score = {33, 56, 78, 45, 77, 90};
  //原始列表元素：
  std::cout<<"原始列表元素： "<<std::endl;
  displaylist(score);
  displaylist(name);

  //列表排序
  std::sort(score.begin(), score.end());
  std::sort(name.begin(), name.end());

  std::cout<<"排序后的元素："<<std::endl;
  displaylist(name);
  displaylist(score);
}