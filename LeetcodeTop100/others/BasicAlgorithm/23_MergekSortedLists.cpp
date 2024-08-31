/* 题目描述: 23_合并k个升序链表
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.

 
Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []

*/

#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;


struct ListNode {
    int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};



class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
      //分治算法
      //使用分治方法合并，即两两合并链表，直至合并完毕。这是一个递归过程，类似于归并排序中的合并过程。
      if(lists.empty()) return nullptr;
      int interval = 1;
      while (interval < lists.size())
      {
        for(int i=0; i+interval < lists.size(); i += interval*2){
          lists[i] = mergeTwoLists(lists[i], lists[i + interval]);
        }
        interval *=2;
      }
      
      return lists[0];
    }
private:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2){
      ListNode dump(0);
      ListNode* tail = &dump;
      while (l1 && l2)
      {
        if (l1->val < l2->val) {
          tail->next = l1;
          l1 = l1->next;
        } else {
          tail->next = l2;
          l2 = l2->next;
        }
        tail = tail->next;
      }
      tail->next = l1 ? l1:l2;
      return dump.next;
    }
};


bool isEqual(ListNode* l1, ListNode* l2){
  ListNode* p1 = l1;
  ListNode* p2 = l2;
  while (p1 != nullptr && p2!= nullptr)
  {
    if(p1->val != p2->val)return false;
    p1 = p1->next;
    p2 = p2->next;
  }
  
   return true;
}
//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);
    
    ListNode* target = new ListNode(1);
    target->next = new ListNode(1);
    target->next->next = new ListNode(1);
    target->next->next = new ListNode(2);
    target->next->next->next = new ListNode(3);
    target->next->next->next->next = new ListNode(4);
    target->next->next->next->next->next = new ListNode(4);
    target->next->next->next->next->next->next = new ListNode(5);
    target->next->next->next->next->next->next->next = new ListNode(6);

    vector<ListNode*> lists = {l1,l2, l3};
    EXPECT_TRUE(isEqual(target, solut.mergeKLists(lists)));
}


TEST(XXXTEST, case2){
  Solution solut;
  vector<ListNode*> lists = {};
  ListNode* target =nullptr;
  EXPECT_TRUE(isEqual(target, solut.mergeKLists(lists) ));
  
}


int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
