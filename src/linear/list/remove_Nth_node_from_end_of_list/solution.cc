#include "solution.h"

// 解法1: 两次遍历
//  先得到list长度len
//  然后从头走 len - n即可
// 解法2：一次遍历
//  设置两个步长差N的指针扫描
//  设置一个头节点，使得代码更简洁

ListNode* Solution::removeNthFromEnd(ListNode* head, int n) {
  if (head == nullptr) return nullptr;
  ListNode dummy(0, head); // 设置头节点
  ListNode *p, *q, *r;
  r = &dummy;
  p = q = r->next;
  while (n-- > 0 && p) {
    p = p->next;
  }
  while (p) {
    r = q;
    q = q->next;
    p = p->next;
  }
  r->next = q->next;
  delete q;
  return dummy.next; // 这里不能return head
}

