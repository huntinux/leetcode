#include <iostream>

#include "solution.h"

// start: 18点50分
//    n1->n2->n3->N
// p  c   n
// N<-n1
//    p   c   n
// end: 18点57分
Node* Solution::ReverseLinkedList(Node* head) {
  // if (head == nullptr) return nullptr;
  Node* prev = nullptr;
  Node* curr = head;
  while (curr) {
    Node* next = curr->next;
    curr->next = prev;
    prev = curr;
    curr = next;
  }
  return prev;
}

// 2022年3月20日
// start: 19点06分
// a    b    c    d    N
//      m         n
// shp sh         st   stn
//     sc
// end: 19点23分
// ac: 19点46分
//
// 总结：
// 总体思路时正确的，中间查找sub_tail时变量控制有问题，debug问题的速度有待提高
// 以后先分析问题，制定好总体思路，然后注释example，快速写出代码
// 边界问题输出中间变量进行debug
Node* Solution::ReverseLinkedListBetween(Node* head, int m, int n) {
  // find sub-head-prev sub-head sub-tail sub-tail-next
  // reverse [sub-head, sub-tail]
  // sub-head-prev->new-head..->new-tail->sub-tail-next
  Node* prev = nullptr;
  Node* curr = head;
  int i = 1;
  while (i < m && curr) {
    prev = curr;
    curr = curr->next;
    i++;
  }

  Node* sub_head_prev = prev;
  Node* sub_head = curr;

  while (i <= n) {
    prev = curr;
    curr = curr->next;
    i++;
  }
  Node* sub_tail = prev;
  Node* sub_tail_next = curr;

  // std::cout << "sub_tail: " << sub_tail->value
  //          << "sub_tail_next:" << sub_tail_next->value << std::endl;

  // revert sub list
  Node* sub_prev = sub_tail_next;
  Node* sub_curr = sub_head;
  while (sub_curr != sub_tail_next) {
    Node* sub_next = sub_curr->next;
    sub_curr->next = sub_prev;
    sub_prev = sub_curr;
    sub_curr = sub_next;
  }
  Node* sub_new_head = sub_prev;
  if (sub_head_prev) sub_head_prev->next = sub_new_head;
  return (sub_head_prev) ? head : sub_new_head;
}
