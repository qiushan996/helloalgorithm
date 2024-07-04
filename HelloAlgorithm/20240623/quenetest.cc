#include<queue>
#include<iostream>

int main(){
  //初始化
  std::queue<std::string>  que;
  que.push("Google");
  que.push("meat");
  que.push("facebook");
  que.push("twitter");
  que.push("Amazon");

  //遍历
  // while(!que.empty()){
  //   std::cout<<que.front()<<", ";
  //   que.pop();
  // }
  // std::cout<<std::endl;

  std::cout<<"que 大小: "<<que.size()<<std::endl;

  std::cout<<"第一个元素："<<que.front()<<", 最后一个元素："<<que.back()<<std::endl;
}