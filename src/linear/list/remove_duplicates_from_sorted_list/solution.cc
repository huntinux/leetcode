#include "solution.h"

// Node* Solution::DeleteDuplicates(Node* head) {
//  Node* curr = head;
//  while (curr && curr->next) {
//    Node* prev = curr;
//    curr = curr->next;
//    while (curr && prev && prev->value == curr->value) {
//      Node* next = curr->next;
//      delete curr;
//      prev->next = next;
//      curr = next;
//    }
//  }
//  return head;
//}

Node* Solution::DeleteDuplicates(Node* head) {
  if (head == nullptr) return nullptr;
  for (Node *prev = head, *cur = head->next; cur; cur = prev->next) {
    if (prev->value == cur->value) {
      prev->next = cur->next;
      delete cur;
    } else {
      prev = cur;
    }
  }
  return head;
}

// 利用dummy头节点的解法
ListNode* deleteDuplicates(ListNode* head) {
  if (head == nullptr) return nullptr;
  ListNode dummy(head->val - 1, head);
  ListNode *curr = head, *prev = &dummy;
  while (curr) {
    if (curr->val == prev->val) {
      prev->next = curr->next;
      delete curr;
      curr = prev->next;
    } else {
      prev = curr;
      curr = curr->next;
    }
  }
  return dummy.next;
}
