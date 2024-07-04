#include"mystack.h"
#include<iostream>

int main(){
  Stacklink app;
  app.push(45);
  app.push(88);
  app.push(20);
  app.push(86);
  app.push(34);

  std::cout<<"栈大小："<<app.size()<<", 栈顶元素："<<app.top()<<std::endl;
  //获取栈中的元素
  std::vector<int> result = app.tovector();
  for(auto val :result){
    std::cout<<val<<", ";
  }
  std::cout<<std::endl;


  //循环遍历
  while (!app.isEmpty())
  {
    std::cout<<app.top()<<std::endl;
    app.pop();
  }

  std::cout<<"栈大小："<<app.size()<<std::endl;
  
  //=================================
  StackArry arrpp;
  arrpp.push(45);
  arrpp.push(88);
  arrpp.push(20);
  arrpp.push(86);
  arrpp.push(34);
  std::cout<<"栈大小:" <<arrpp.size()<<"栈顶元素：" <<arrpp.top()<<std::endl;
  //循环
  while(!arrpp.isempty()){
     std::cout<<arrpp.top()<<",";
     arrpp.pop();
  }
  std::cout<<"\n栈大小：" <<arrpp.size()<<std::endl;
}