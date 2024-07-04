#include<iostream>

/* 数组的操作：
- 访问数组中的元素：任意任意下标、数组遍历
- 插入元素
-删除元素：

*/


/*
函数功能：向数组中插入一个元素:数组是固定大小的，因此插入元素时必须扩展容量
nums: 原始数组
size： 原数组大小
target_index: 要插入的位置
target_value: 要插入的值
*/
int* insert(int* nums, int size, int target_index, int target_value){

  int* result = new int[size+1];
  
  // 插入位置为原数组末尾
  if(size == target_index){
    result = nums;
    result[target_index] = target_value;
    return result;
  }

  //插入位置为原数组开头
  if(target_index==0){
    result[0]=target_value;
    for(size_t i=1; i<size; i++){
      result[i] = nums[i-1];
    }
    return result;
  }

  for(size_t i=0;i<size+1; i++){
    if(i<target_index)result[i] = nums[i];
    else if (i==target_index)result[i] = target_value;
    else{
      result[i+1] = nums[i];
    }
    std::cout<<result[i+1]<<"---"<<nums[i]<<std::endl;    
  }

  return result;

};

int* deletearr(int* nums, int size, int index){
  int*  result = new int[size-1];
  //删除的元素在原数组末尾
  if(index == size){
    for(size_t i =0; i<size-1; i++){
      result[i] = nums[i];
    }
  }

  for(int i=0; i<size; i++){
    if(i<index) result[i] = nums[i];
    else  result[i] = nums[i+1];
  }
  return result;
}

void init(){
//数组的初始化
//1 将数组分配在栈上
char  name[10];
char  name2[]={'h', 'e', 'l', 'l', 'o'};
char  name3[]= "this is a definitation of a array";

//2 将数组分配在堆上， 需要手动释放空间
int*  num1 = new int[10];
int*  num2 = new int[10]{3,2,54,1,1,1,1,4,2,2};
//访问元素
int len = strlen(name3);
std::cout<<"char 数组 name3: "<<std::endl;
for (size_t i = 0; i < len; i++)
{
  std::cout<<name3[i]<<"";
}
std::cout<<std::endl;

std::cout<<"堆上数组: "<<std::endl;
for(size_t i =0; i<15; i++){
  std::cout<<num2[i];
}


delete[] num1;
delete[]  num2;
}
int main(int argc, char* argv[]){

  int* arr = new int[5]{2,4,5,12,7};
  for(int i=0; i<5; i++){
    std::cout<<arr[i]<<" ";
  }
  std::cout<<std::endl;
  //插入
  // int* arr_new = insert(arr, 5, 0, 66);
  // int* arr_new_tail = insert(arr, 5, 5,55);
  // int* arr_new_mid = insert(arr, 5, 2, 78);

  //删除
  int* delearr = deletearr(arr, 5,5);
  //cout
  for (size_t i = 0; i < 6; i++)
  {
    std::cout<<delearr[i]<<" ";
  }
  std::cout<<std::endl;  

  delete[] arr;
  delete[] delearr;

}