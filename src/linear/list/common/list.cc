#include "list.h"

#include <sstream>

namespace list {

void ReleaseList(Node* head) {
  Node* cur = head;
  while (cur) {
    Node* next = cur->next;
    delete cur;
    cur = next;
  }
}

std::string DebugList(Node* head) {
  std::stringstream ss;
  Node* cur = head;
  while (cur) {
    ss << cur->value << "->";
    cur = cur->next;
  }
  ss << "NULL";
  return ss.str();
}

}  // namespace list
