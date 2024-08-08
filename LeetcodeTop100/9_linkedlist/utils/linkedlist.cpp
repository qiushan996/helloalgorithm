#include "linkedlist.h"

bool isEqualLinkedlists(ListNode *node1, ListNode *node2)
{
  ListNode* pa = node1;
  ListNode* pb = node2;
  
  while ( pa !=NULL && pb !=NULL)
  {
    if(pa->val !=pb->val) return false;
    //cout<<"pa: "<<pa->val<<" pb: "<<pb->val<<endl;
    pa = pa->next;
    pb = pb->next;
  }
  
  return pa == NULL && pb == NULL;
}