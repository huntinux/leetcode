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
  for (Node* prev = head, *cur = head->next; cur; cur = prev->next) {
    if (prev->value == cur->value) {
      prev->next = cur->next;
      delete cur;
    } else {
      prev = cur;
    }
  }
  return head;
}
