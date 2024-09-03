/*题目描述: 705_设计哈希集合
Design a HashSet without using any built-in hash table libraries.

Implement MyHashSet class:

void add(key) Inserts the value key into the HashSet.
bool contains(key) Returns whether the value key exists in the HashSet or not.
void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.

Example 1:

Input
["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
[[], [1], [2], [1], [3], [2], [2], [2], [2]]
Output
[null, null, null, true, false, null, true, null, false]

Explanation
MyHashSet myHashSet = new MyHashSet();
myHashSet.add(1);      // set = [1]
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(1); // return True
myHashSet.contains(3); // return False, (not found)
myHashSet.add(2);      // set = [1, 2]
myHashSet.contains(2); // return True
myHashSet.remove(2);   // set = [1]
myHashSet.contains(2); // return False, (already removed)

*/
#include<vector>
#include<list>
#include<gtest/gtest.h>

using namespace std;


//自定义的哈希表。考虑实现方式：
// - 静态数组
// - 数组嵌套链表

class MyHashSet {
private:
  vector<list<int>>  data;  //链地址法
  static const int base =769;   //为什么是769:质数、较小且容纳空间较大；解决冲突

  //定义hash函数
  static int hash(int key){
    return key % base;
  }
public:
    MyHashSet():data(base) {
    }
    
    void add(int key) {
      int index = hash(key);
      for(auto it = data[index].begin(); it!=data[index].end(); it++){
        if(*it == key){
          return;  //key已经存在，解决冲突
        }
      }
      data[index].push_back(key);
    }
      
    
    void remove(int key) {
      int index = hash(key);
      for(auto it = data[index].begin(); it!=data[index].end(); it++){
        if(*it == key){
          data[index].erase(it);
          return ;
        }
      }
    }
    
    bool contains(int key) {
      int index = hash(key);
      for(auto it = data[index].begin(); it!=data[index].end(); it++){
        if(*it == key) return true;
      }
      return false;
    }
};

//测试用例
TEST(XXXTest, Case1){
    MyHashSet solut;
    solut.add(1);
    solut.add(2);
    EXPECT_TRUE(solut.contains(1));
    EXPECT_FALSE(solut.contains(3));
    solut.add(2);
    EXPECT_TRUE(solut.contains(2));
    solut.remove(2);
    EXPECT_FALSE(solut.contains(2));
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
