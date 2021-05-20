#pragma once

template <typename T>
struct ListNode {
  ListNode(const T& v) : value(v), next(nullptr) {}
  T value;
  ListNode* next;
};

using Node = ListNode<int>;

class Solution {
 public:
  Node* ReverseLinkedList(Node* head);
  // Given  1->2->3->4->5->NULL m = 2 n = 4
  // return 1->4->3->2->5->NULL
  Node* ReverseLinkedListBetween(Node* head, int m, int n);
};
