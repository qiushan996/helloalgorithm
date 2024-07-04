#include<unordered_map>
#include<unordered_set>
#include<iostream>

using namespace std;

void test_map(){
  //定义一个map类型的哈希表
  unordered_map<string, int>  class11;
  //插入元素
  class11["zhangsan"] = 45;
  class11["Lisi"] =  76;
  class11["wangwu"] = 88;
  class11["DuWenjia"] = 100;
  class11["Danan"] = 99;
  //class11.insert("Qibajiu", 99);
  class11.insert({"zhanga", 88});
  class11.insert(make_pair("zhangYong", 67));

  //获取哈希表的值
  cout<<class11["zhangsan"]<<endl;

  //遍历哈希表: for循环
  for(auto k:class11){
      cout<<k.first<<"->"<<k.second<<endl;
  }

  cout<<"迭代器遍历哈希表："<<endl;
  //遍历哈希表：迭代器
  for(auto iter=class11.begin(); iter!=class11.end();iter++){
      cout<<iter->first<<"-->"<<iter->second<<endl;
  }
}


void test_set(){
  //只存储唯一元素的集合，并不支持键值对存储
  //不允许存储重复元素
  //元素按照散列值进行组织，因此其查找、插入和删除操作平均时间复杂度为 O(1)。
  
  unordered_set<string> class001;  //定义一个set类型的哈希表

  //插入元素
  class001.insert("zhangsan");
  class001.insert("Lisi");
  class001.insert("Wangwu");
  class001.insert("DuJJ");
  class001.insert("ZhaoMin");
  class001.insert("DuDuD");
  class001.insert("XiaoWu");

  //常熟插入重复元素
  auto result = class001.insert("Lisi");
  if(!result.second){
    cout<<"Sorry, but the element is already exists"<<endl;
  }

  //遍历哈希表
  int i = 0;
  for(auto v :class001){
    cout<<i++<<": "<<v<<endl;
  }

   //删除元素
   //class001.erase("DuDuD");

  //查找元素
  if(class001.find("DuDuD")!=class001.end()){
    cout<<"Congratulations, Find the `DuDuD` in the hashtable"<<endl;
  }else{
    cout<<"Sorry, Can't find the target element"<<endl;
  }
  
 

}
int main(){
  test_set();
  test_map();

  return 0; 
}