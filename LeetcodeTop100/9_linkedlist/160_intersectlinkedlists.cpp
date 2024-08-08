/*  题目描述： 160_相交链表
Given the heads of two singly linked-lists headA and headB, return the node at which the two lists intersect. If the two linked lists have no intersection at all, return null.
*/
#include<vector>
#include<algorithm>
#include<gtest/gtest.h>

using namespace std;

struct ListNode {
      int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(!headA || !headB) return NULL;
        //双指针
        ListNode* pa = headA;
        ListNode* pb = headB;
        //遍历链表
        //当两个指针不相等时，继续遍历链表。如果一个指针到达链表末尾，则将其指向另一个链表的头节点。
        while (pa!=pb)
        {
          pa = pa? pa->next: headB;
          pb = pb? pb->next: headA;
        }
        //返回相交节点
        return pa;
    }
};

//测试用例
TEST(XXXTest, Case1){
    Solution solut;
    ListNode *intersect = new ListNode(8);
    intersect->next = new ListNode(4);
    intersect->next->next = new ListNode(5);

    ListNode *headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = intersect;

    ListNode *headB = new ListNode(5);
    headB->next = new ListNode(0);
    headB->next->next = new ListNode(1);
    headB->next->next->next = intersect;

    ListNode *result = solut.getIntersectionNode(headA, headB);
    EXPECT_EQ(8, result->val);
}

TEST(XXXTest, Case2){
    Solution solut;
    ListNode *intersect = new ListNode(2);
    intersect->next = new ListNode(4);

    ListNode *headA = new ListNode(1);
    headA->next = new ListNode(9);
    headA->next->next = new ListNode(1);
    headA->next->next->next = intersect;

    ListNode *headB = new ListNode(3);
    headB->next = intersect;

    ListNode *result = solut.getIntersectionNode(headA, headB);
    EXPECT_EQ(2, result->val);
}

int main(int argc, char* argv[]){
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
