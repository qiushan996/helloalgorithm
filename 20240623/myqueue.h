#include <stdexcept>
#include<iostream>

//链表节点
struct myqueue_list
{
  float value;
  myqueue_list* next;
  myqueue_list(float val): value(val), next(nullptr){};
};


//由链表实现的队列
class Queuelinked{
  private:
  myqueue_list *front, *back;
  int quesize;

  public:
  //构造函数
  Queuelinked():front(nullptr), back(nullptr), quesize(0){}
  //析构函数
  ~Queuelinked(){
    // myqueue_list* pre;
    // while (front!=nullptr)
    // {
    //   front = pre;
    //   pre = pre->next;
    //   delete pre;
    // }

    while (!isEmpty())
    {
      pop();
    }
    
  }
  //获取队列大小
  int size(){
    return quesize;
  }
  //判断队列是否为空
  bool isEmpty(){
    return quesize ==0;
  }
  //在队列尾部插入一个元素
  void push(float val){
    myqueue_list* node = new myqueue_list(val);
    //当队列为空时，front、back都等于第一个值
    if(front==nullptr){
      front = node;
      back = node;
    }else{
      back->next = node;  //当队列不为空时，向back后面插入值，并保持back始终指向最后一个元素
      back = node;
    }
    quesize++;
  }

  //获取队列首元素
  float top(){
    if(size()==0)
      throw std::out_of_range("队列为空");
    return front->value;
  }

  //删除队列第一个元素
  float pop(){
    float num = top();
    myqueue_list* tmp = front;
    front = front->next;
    delete tmp;
    quesize--;
    return  num;
  }

  void dispaly(){
    myqueue_list* tmp = front;
    for(int i=0; i<size();i++){
      std::cout<<tmp->value<<", ";
      tmp = tmp->next;
    }
    std::cout<<std::endl;
  }
};


//由数组实现的队列
template <typename T>
class ArrayQue{
  private:
    T* nums;
    int quesize; // 队列长度
    int queCapacity; //队列容量
    int front;   //指向首元素的指针
  
  public:

  ArrayQue(int capcacity){
    //初始化
    nums =  new T[capcacity];
    queCapacity = capcacity;
    quesize = 0;
    front = 0;   //第一次忽略了 bug

  }
  ~ArrayQue(){
    delete[] nums;
  }

  //获取容量
  int Capacity(){
    return queCapacity;
  }

  //获取队列大小
  int Size(){
    return quesize;
  }

  //判断队列是否为空
  bool isEmpty(){
    return Size()==0;
  }

  //获取首元素
  T peek(){
    if(Size()==0)
      throw std::out_of_range("队列为空");
    return nums[front]; 
  }
  //入队操作
  void push(const T& value){
    if(quesize == queCapacity){
      std::cout<<"队列已满"<<std::endl;
      return ;
    }
    //计算插入坐标，循环数组
    int rear = (front+quesize)%queCapacity;
    nums[rear] = value;
    quesize++;
    // std::cout<<"插入元素成功！"<<std::endl;
  }
  //出队操作
  T pop(){
    T ele = peek();
    front = (front+1)%queCapacity;
    quesize--;
    std::cout<<"出队操作成"<<std::endl;
    return ele;
  }

  //打印队列中的元素
  void display(){
    int len = Capacity();
    for(int i=0; i<len; i++){
      std::cout<<nums[i]<<", ";
      //pop();
    }
    std::cout<<std::endl;
  }

};