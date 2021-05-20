#pragma once

#include <vector>
#include <string>

namespace list {
template <typename T>
struct ListNode {
  ListNode(const T& v) : value(v), next(nullptr) {}
  T value;
  ListNode* next;
};

using Node = ListNode<int>;

template <typename T>
Node* BuildList(const std::vector<T>& elems) {
  Node* head = nullptr;
  Node* tail = nullptr;
  for (auto e : elems) {
    Node* node = new Node(e);
    if (!head) {
      head = node;
      tail = node;
    } else {
      tail->next = node;
      tail = node;
    }
  }
  return head;
}

void ReleaseList(Node* head);
std::string DebugList(Node* head);

}  // namespace list
