/*题目描述: 706_设计一个哈希映射

Design a HashMap without using any built-in hash table libraries.
Implement the MyHashMap class:
MyHashMap() initializes the object with an empty map.
void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.
 

Example 1:
Input
["MyHashMap", "put", "put", "get", "get", "put", "get", "remove", "get"]
[[], [1, 1], [2, 2], [1], [3], [2, 1], [2], [2], [2]]
Output
[null, null, null, 1, -1, null, 1, null, -1]

Explanation
MyHashMap myHashMap = new MyHashMap();
myHashMap.put(1, 1); // The map is now [[1,1]]
myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]

*/
#include<vector>
#include<list>
#include<gtest/gtest.h>

using namespace std;

// 方法：链地址法

// 	1.	初始化：创建一个固定大小的数组，数组的每个位置初始为空链表。
// 	2.	哈希函数：设计一个哈希函数，用于将键映射到数组的索引。
// 	3.	操作实现：
// 	•	put：计算哈希值，找到对应的链表，检查键是否存在，存在则更新值，不存在则添加新的节点。
// 	•	get：计算哈希值，遍历对应链表，返回找到的值，否则返回 -1。
// 	•	remove：计算哈希值，找到对应链表，如果找到节点，则删除。
class MyHashMap {
private:
    vector<list<std::pair<int,int>>> map;
    static const int base = 769;
    static int hash(int key){
      return key%base;
    }
public:
    MyHashMap() {
      map.resize(base);
    }
    
    void put(int key, int value) {
      auto &bucket = map[hash(key)];
      for(auto& it: bucket){
        if(it.first == key){
          it.second = value;
          return;
        }
      }
      bucket.push_back({key, value});
    }
    
    int get(int key) {
      auto& bucket = map[hash(key)];
      for(auto& pair: bucket){
        if(pair.first == key){
          return pair.second;
        }
      }
      return -1;
    }
    
    void remove(int key) {
      auto& bucket = map[hash(key)];
      for(auto it = bucket.begin(); it!=bucket.end(); it++){
        if(it->first == key){
          bucket.erase(it);
          return;
        }
      }
    }
};

//测试用例
TEST(XXXTest, Case1){
    MyHashMap solut;
    solut.put(1,1);
    solut.put(2,2);
    EXPECT_EQ(1, solut.get(1));
    EXPECT_EQ(-1, solut.get(3));

    solut.put(2,1);
    EXPECT_EQ(1, solut.get(2));
    solut.remove(2);
    EXPECT_EQ(-1, solut.get(2));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
