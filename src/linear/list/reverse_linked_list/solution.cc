#include "solution.h"

Node* Solution::ReverseLinkedList(Node* head) {
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

// 解法借鉴 ReverseLinkedList
// 先找到开始反转的点，记为start，以及它的前驱prev_start
// 开始反转：结束后，子串反转后的新head为prev
// 领反转前驱节点prev_start指向子串的新head，即prev： prev_start->next = prev；
// 注意判断prev_start是否为空
// start->next指向剩余未反转的元素即可
// 最后返回的新head分情况，如果首个元素参与反转了，则返回子串的新head，即prev
// 否则返回原来的head即可
Node* Solution::ReverseLinkedListBetween(Node* head, int m, int n) {
  Node* prev_start = nullptr;
  Node* start = head;
  int i = 0;
  while (++i < m) {
    prev_start = start;
    start = start->next;
  }

  Node* prev = nullptr;
  Node* curr = start;
  Node* next = nullptr;
  while (i++ <= n) {
    next = curr->next; 
    curr->next = prev;
    prev = curr;
    curr = next;
  }

  if (prev_start) prev_start->next = prev;
  start->next = next;

  return (m > 1) ? head : prev;
}
