#include "solution.h"

// 输入链表： 1->1->1->2->3
//  (0)  ->    1    ->      1    ->     1    ->    2   ->   3
//  curr_prev  curr
//  del_prev   curr_prev    curr
//             node 
//  (0)  ->    2    ->      3    ->    null
//  del_prev   node
//  curr_prev  curr
//
//  del_prev   curr_prev    curr
//             del_prev     curr_prev  curr
//
// 输入链表  1->1->1->2->2
//  (0)  ->    1    ->      1    ->     1    ->    2   ->   3
//  curr_prev  curr
//  del_prev   curr_prev    curr
//             node 
//  (0)  ->    2    ->      2    ->    null
//  del_prev   node
//  curr_prev  curr
//
//  del_prev   curr_prev    curr
//             node
//
// 时间复杂度：O(N)
// 空间复杂度：O(1)
ListNode* deleteDuplicates(ListNode* head) {
  if (!head || !head->next) return head;
  ListNode dummy;
  dummy.val = head->val - 1;
  dummy.next = head;
  ListNode* curr_prev = &dummy;
  ListNode* curr = head;
  ListNode* del_prev = nullptr;
  while (curr) {
    if (curr_prev->val == curr->val) {
      int val = curr_prev->val;
      ListNode* node = curr_prev;
      while (node && val == node->val) {
        del_prev->next = node->next;
        ListNode* del_node = node;
        node = node->next;
        delete del_node;
      }
      curr_prev = del_prev;
      curr = node;
    } else {
      del_prev = curr_prev;
      curr_prev = curr;
      curr = curr->next;
    }
  }
  return dummy.next;
}
