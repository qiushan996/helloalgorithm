#include<deque>
#include<iostream>


int main(){
  //初始化双向队列
  std::deque<float>  dq;
  dq.push_front(12.45);
  dq.push_front(23.00);
  dq.push_back(8964);
  dq.push_back(78.8990);

  std::cout<<dq.size()<<std::endl;

  //遍历
  while (!dq.empty())
  {
    std::cout<<dq.front()<<", ";
    dq.pop_front();
    // std::cout<<dq.back()<<", ";
    // dq.pop_back();
  }
  std::cout<<std::endl;
  std::cout<<dq.size()<<std::endl;
  return 0;
  
}