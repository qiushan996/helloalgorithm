#include<map>
#include<iostream>

using namespace std;

int main(){
  //定义map变量
   map<string, string>  mp;
   mp["En"] = "english";
   mp["cn"] = "Chinese";
   mp["Jan"] = "Japanse";

   mp.insert(make_pair("Germ","German"));
   mp.insert({"Inda", "Indan"});

   //遍历元素
   for(auto pair:mp){
      cout<<pair.first<<"->"<<pair.second<<endl;
   }
   cout<<endl;
   //查找元素
   if(mp.count("cns")==0){
    cout<<"key is not found in the map "<<endl;
   }else{
    cout<<"Key is found in the map"<<endl;
   }
   //删除元素
   mp.erase("En");   //参数只能为Key类型
   cout<<"at(3): "<<mp.at("Inda")<<" size: "<<mp.size()<<endl;
   
   //修改元素
   mp.at("cn") = "CHINESE";
   for(auto iter =mp.begin(); iter!=mp.end(); ++iter){
    cout<<iter->first<<"-->"<<iter->second<<endl;
   }
   //清空map
   mp.clear();
   cout<<"mp size: "<<mp.size()<<endl;

}