#include<set>
#include<unordered_set>
#include<iostream>

#include<map>
#include<unordered_map>

#include<hash_map>

using namespace std;


int main(){
  //定义变量
  set<int> tset;
  multiset<int> tmset;  //关键字可重复的set

  tset.insert(22);
  tset.insert(34);
  tset.insert(79);
  tset.insert(567);
  tset.insert(34);

  cout<<"set 容器的大小："<<tset.size()<<"\nset容器的max_size(): "<<tset.max_size()<<endl;

  //遍历
  cout<<"set中的元素:"<<endl;
  for(auto iter=tset.begin(); iter!=tset.end(); iter++){
    cout<<*iter<<endl;
  }
  cout<<"find(79): "<<*tset.find(79)<<"count(79): "<<tset.count(79)<<endl;


  //unorded_set: 关键字唯一不可重复
  unordered_multiset<string> mtunset;
  //unorded_multiset: 无序可重复
  unordered_multiset<int> tunset;
  tunset.insert(22);
  tunset.insert(34);
  tunset.insert(79);
  tunset.insert(79);
  tunset.insert(567);
  tunset.insert(34);

  for(auto it = tunset.begin(); it!=tunset.end(); ++it ){
    cout<<*it<<endl;
  }

  // 查找
  cout<<"find(79): "<<*tunset.find(79)<<"count(79): "<<tunset.count(79)<<endl;


  //==================map===========
  map<int, int>  tmap;
  multimap<string, int> mulmap;
  unordered_map<int, int> untmap;
  unordered_multimap<string, string> unmulmap;


}